#ifndef LIGHTRENDERER_H
#define LIGHTRENDERER_H
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Mesh.h>
#include <Shader.h>
#include <Camera.h>

class LightRenderer {
public:
  LightRenderer(MeshType meshType, Camera* cam);
  ~LightRenderer();
  
  void Draw();
  void SetPosition(glm::vec3 _position);
  void SetColor(glm::vec3 _color);
  void SetProgram(GLuint _program);
  
  glm::vec3 GetPosition();
  glm::vec3 GetColor();
  
private:
  Camera* camera;
  vector<Vertex> vertices;
  vector<uint32_t> indices;
  glm::vec3 position, color;
  GLuint vbo, ebo, vao, program;
};

#endif