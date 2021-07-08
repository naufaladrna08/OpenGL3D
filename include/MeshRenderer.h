#ifndef MESHRENDERER_H
#define MESHRENDERER_H
#include <vector>
#include <Camera.h>
#include <LightRenderer.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;

class MeshRenderer {
public:
  MeshRenderer(MeshType mt, Camera* camera);
  ~MeshRenderer();
  void Draw();
  
  void SetPosition(glm::vec3 _pos);
  void SetScale(glm::vec3 _scale);
  void SetProgram(uint32_t _program);
  void SetTexture(uint32_t _texture);

private:
  std::vector<Vertex> vertices;
  std::vector<uint32_t> indices;
  glm::mat4 modelMatrix;
  
  Camera* camera;
  glm::vec3 position, scale;
  uint32_t vao, vbo, ebo, texture, program;
};

#endif