#include <iostream>
#include <memory>
#include "Texture2d.h"
#include "glad/glad.h"
#include "stb/stb_image.h"

using namespace winter;

Texture2d::Texture2d(TextureId textureId, int width, int height):
        _textureId(textureId),
        _width(width),
        _height(height) {}

Texture2d::~Texture2d() {
    glDeleteTextures(1, &_textureId);
}

std::unique_ptr<Texture2d> Texture2d::loadFromFile(const std::string &filename) {
    int channels, width, height;

    stbi_set_flip_vertically_on_load(true);
    unsigned char* rawData = stbi_load(
            filename.c_str(),
            &width,
            &height,
            &channels,
            0);

    if (rawData){
        TextureId textureId;

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, rawData);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(rawData);

        return std::make_unique<Texture2d>(textureId, width, height);
    }
    else {
        std::cout << "Error loading SetTexture " << filename << std::endl;
    }

    return nullptr;
}
