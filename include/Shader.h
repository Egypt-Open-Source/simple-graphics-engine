#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "../vendors/glad/include/glad/glad.h"
#include "../vendors/glm/glm/glm.hpp"

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setMat4(const std::string& name, const glm::mat4& mat);
    void setVec3(const std::string& name, const glm::vec3& value);

private:
    GLuint ID;
    std::string readFile(const char* filePath);
    void checkCompileErrors(GLuint shader, std::string type);
};

#endif