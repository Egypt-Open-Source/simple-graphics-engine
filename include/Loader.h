#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <vector>
#include "../vendors/glm/glm/glm.hpp"

class Loader {
public:
    bool loadOBJ(const std::string& filepath, std::vector<float>& vertices, std::vector<unsigned int>& indices, glm::vec3& center, float& scale);
};

#endif
