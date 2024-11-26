#include "../include/Loader.h"
#include "../vendors/tinyobjloader/tiny_obj_loader.h"
#include "../vendors/glm/glm/gtc/matrix_transform.hpp"
#include <limits>
#include <iostream>

bool Loader::loadOBJ(const std::string& filepath, std::vector<float>& vertices, std::vector<unsigned int>& indices, glm::vec3& center, float& scale) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filepath.c_str())) {
        std::cerr << warn << err << std::endl;
        return false;
    }

    glm::vec3 minPoint(std::numeric_limits<float>::max());
    glm::vec3 maxPoint(std::numeric_limits<float>::lowest());

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            float x = attrib.vertices[3 * index.vertex_index + 0];
            float y = attrib.vertices[3 * index.vertex_index + 1];
            float z = attrib.vertices[3 * index.vertex_index + 2];

            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            minPoint = glm::min(minPoint, glm::vec3(x, y, z));
            maxPoint = glm::max(maxPoint, glm::vec3(x, y, z));
        }
    }

    center = (minPoint + maxPoint) * 0.5f;
    scale = 1.0f / glm::length(maxPoint - minPoint) * 2.0f; // Medium size
    return true;
}
