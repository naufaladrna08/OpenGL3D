#ifndef MESH_H
#define MESH_H
#include <vector>
#include <glm/glm.hpp>
using namespace std;

enum MeshType {
  TRIANGLE = 0,
  QUAD = 1,
  CUBE = 2, 
  SPHERE = 3
};

struct Vertex {
  glm::vec3 pos;
  glm::vec3 color;
  glm::vec3 normal;  
  glm::vec2 texCoords;
};

/**
 * @class Mesh
 * @author Naufal Adriansyah
 * @date 18/06/21
 * @file Mesh.h
 * @brief Mesh Class
 */
class Mesh {
public:
  static void SetTriangleData(vector<Vertex>& vertices, vector<uint32_t>& indices);
  static void SetQuadData(vector<Vertex>& vertices, vector<uint32_t>& indices);
  static void SetCubeData(vector<Vertex>& vertices, vector<uint32_t>& indices);
  static void SetSphereData(vector<Vertex>& vertices, vector<uint32_t>& indices);
};

#endif 