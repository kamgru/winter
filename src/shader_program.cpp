#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "shader_program.h"
#include "file_io.h"

using namespace winter;

typedef unsigned int shader_id;

const int INFO_LOG_BUFFER_SIZE = 512;
char info_log[INFO_LOG_BUFFER_SIZE];
const char* MAIN_TEX_UNIFORM_NAME = "_mainTex";

shader_program::shader_program() {
    m_program_id = glCreateProgram();
}

shader_program::~shader_program() {
    glDeleteProgram(m_program_id);
}

GLenum translate_shader_type(SHADER_TYPE shader_type) {
    switch (shader_type) {
        case SHADER_TYPE_VERTEX: return GL_VERTEX_SHADER;
        case SHADER_TYPE_FRAGMENT: return GL_FRAGMENT_SHADER;
        default: return 0;
    }
}

bool compile(shader_id id, const char *src){
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    return success;
}

void print_compile_err(shader_id id){
    glGetShaderInfoLog(id, INFO_LOG_BUFFER_SIZE, NULL, info_log);
    std::cout << "Error compiling shader:\n" << info_log << std::endl;
}

void shader_program::attach_shader_file(SHADER_TYPE shader_type, std::string filename) {
    std::string shader_src = file_io::read_all_text(filename);
    const char* src = shader_src.c_str();

    shader_id shader_id = glCreateShader(translate_shader_type(shader_type));
    if (!compile(shader_id, src)){
        print_compile_err(shader_id);
    }

    glAttachShader(m_program_id, shader_id);
    glLinkProgram(m_program_id);
    int link_success;
    glGetProgramiv(m_program_id, GL_LINK_STATUS, &link_success);
    if (!link_success){
        glGetProgramInfoLog(m_program_id, INFO_LOG_BUFFER_SIZE, NULL, info_log);
        std::cout << "Error linking program:\n" << info_log << std::endl;
    }
    glDeleteShader(shader_id);

    if (shader_type == SHADER_TYPE_FRAGMENT){
        int loc = glGetUniformLocation(m_program_id, MAIN_TEX_UNIFORM_NAME);
        glUniform1i(loc, 0);
    }
}

void shader_program::use() {
    glUseProgram(m_program_id);
}

void shader_program::set_uniform_mat4(std::string name, glm::mat4 mat) {
    int location = glGetUniformLocation(m_program_id, name.c_str());
    if (location >= 0){
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
    }
    else{
        std::cout << "Error, uniform " << name << " not found" << std::endl;
    }
}
