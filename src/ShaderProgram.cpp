#include "glad/glad.h"
#include <iostream>
#include "ShaderProgram.h"
#include "file_io.h"

using namespace winter;

typedef unsigned int ShaderId;

const int INFO_LOG_BUFFER_SIZE = 512;
char info_log[INFO_LOG_BUFFER_SIZE];
const char* MAIN_TEX_UNIFORM_NAME = "_mainTex";

ShaderProgram::ShaderProgram(ShaderProgramId shaderProgramId):
    _shaderProgramId(shaderProgramId) {}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(_shaderProgramId);
}

bool compile(ShaderId id, const char *src){
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    return success;
}

void print_compile_err(ShaderId id){
    glGetShaderInfoLog(id, INFO_LOG_BUFFER_SIZE, nullptr, info_log);
    std::cout << "Error compiling shader:\n" << info_log << std::endl;
}

void ShaderProgram::use() const {
    glUseProgram(_shaderProgramId);
}

void ShaderProgram::SetUniformMatrix(const std::string& name, glm::mat4 mat) const {
    int location = glGetUniformLocation(_shaderProgramId, name.c_str());
    if (location >= 0){
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
    }
    else{
        std::cout << "Error, uniform " << name << " not found" << std::endl;
    }
}

std::unique_ptr<ShaderProgram> ShaderProgram::loadFromFile(const std::string &vertexFilename, const std::string &fragmentFilename) {

    ShaderProgramId shaderProgramId = glCreateProgram();
    auto vertexSource = file_io::read_all_text(vertexFilename);
    auto fragmentSource = file_io::read_all_text(fragmentFilename);

    ShaderId vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    ShaderId fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    if (!compile(vertexShaderId, vertexSource.c_str())){
        print_compile_err(vertexShaderId);
    }

    if (!compile(fragmentShaderId, fragmentSource.c_str())){
        print_compile_err(fragmentShaderId);
    }

    glAttachShader(shaderProgramId, vertexShaderId);
    glAttachShader(shaderProgramId, fragmentShaderId);
    glLinkProgram(shaderProgramId);
    int link_success;
    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &link_success);
    if (!link_success){
        glGetProgramInfoLog(shaderProgramId, INFO_LOG_BUFFER_SIZE, nullptr, info_log);
        std::cout << "Error linking program:\n" << info_log << std::endl;
    }
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    //this is specifically for fragment shader; sets the getTexture uniform location
    int loc = glGetUniformLocation(shaderProgramId, MAIN_TEX_UNIFORM_NAME);
    glUniform1i(loc, 0);

    return std::make_unique<ShaderProgram>(shaderProgramId);
}
