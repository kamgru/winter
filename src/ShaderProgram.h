#ifndef WINTER_SHADERPROGRAM_H
#define WINTER_SHADERPROGRAM_H

#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace winter {

    typedef unsigned int ShaderProgramId;

    class ShaderProgram {
    public:
        explicit ShaderProgram(ShaderProgramId shaderProgramId);
        ~ShaderProgram();

        void SetUniformMatrix(const std::string &name, glm::mat4 mat) const;
        void use() const;
        static std::unique_ptr<ShaderProgram> loadFromFile(const std::string &vertexFilename, const std::string &fragmentFilename);

    private:
        ShaderProgramId _shaderProgramId;
    };
}
#endif
