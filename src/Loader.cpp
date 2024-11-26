#include "../include/Loader.h"
#include "../vendors/tinyobjloader/tiny_obj_loader.h"
#include <iostream>

#define TINYOBJLOADER_IMPLEMENTATION

bool Loader::loadOBJ(const std::string& filepath, std::vector<float>& vertices, std::vector<unsigned int>& indices) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filepath.c_str())) {
        std::cerr << warn << err << std::endl;
        return false;
    }

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 0]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 1]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 2]);
        }
    }
    return true;
}