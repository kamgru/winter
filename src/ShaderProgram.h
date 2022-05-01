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

        void SetUniformMatrix4(const std::string &name, glm::mat4 mat) const;
        void SetUniformMatrix3(const std::string &name, glm::mat3 mat) const;
        void SetUniformVector3(const std::string &name, glm::vec3 vec) const;
        void use() const;
        static std::unique_ptr<ShaderProgram> loadFromFile(const std::string &vertexFilename, const std::string &fragmentFilename);

    private:
        ShaderProgramId _shaderProgramId;
    };
}
#endif
