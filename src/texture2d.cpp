#include <iostream>
#include "texture2d.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb/stb_image.h"

using namespace winter;

texture2d::texture2d() {
}

texture2d::~texture2d() {
    glDeleteTextures(1, &m_id);
}

void texture2d::use() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void texture2d::from_file(std::string filename) {
    int channels;
    raw_texture_data_t data = stbi_load(filename.c_str(), &m_width, &m_height, &channels, 0);
    if (data){
        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Error loading texture " << filename << std::endl;
    }
    stbi_image_free(data);
}
