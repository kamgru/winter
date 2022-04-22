#ifndef WINTER_TEXTURE2D_H
#define WINTER_TEXTURE2D_H

#include <string>
#include <glm/vec2.hpp>
#include <memory>

namespace winter {

    typedef unsigned int TextureId;

    class Texture2d {
    public:
        Texture2d(TextureId textureId, int width, int height);
        ~Texture2d();

        glm::vec2 getSize() const { return {_width, _height}; };
        TextureId getTextureId() const { return _textureId; }

        static std::unique_ptr<Texture2d> loadFromFile(const std::string &filename);

    private:
        TextureId _textureId;
        int _width;
        int _height;
    };
}

#endif
