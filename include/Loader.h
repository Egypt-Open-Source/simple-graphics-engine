#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <string>

class Loader {
public:
    static bool loadOBJ(const std::string& filepath, std::vector<float>& vertices, std::vector<unsigned int>& indices);
};

#endif