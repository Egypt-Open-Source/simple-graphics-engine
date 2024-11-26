# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Ivendors/glfw/include -Ivendors/glad/include -Ivendors/glm -Ivendors/tinyobjloader

# Libraries and linker flags
LDFLAGS = -Lvendors/glfw/lib -lglfw -ldl -lGL

# Source files
SOURCES = main.cpp \
          src/Window.cpp \
          src/Shader.cpp \
          src/Loader.cpp \
          src/Renderer.cpp \
          src/Camera.cpp \
          vendors/glad/src/glad.c \
          vendors/tinyobjloader/tiny_obj_loader.cc

# Output binary
TARGET = 3D_OBJ_Viewer

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(LDFLAGS) -o $(TARGET)

# Clean target
clean:
	rm -f $(TARGET)
