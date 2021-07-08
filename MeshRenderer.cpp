#include <MeshRenderer.h>

MeshRenderer::MeshRenderer(MeshType mt, Camera* camera) {
  this->camera = camera;
  
  scale    = glm::vec3(1.0f);
  position = glm::vec3(0.0f);
  
  
  switch (mt) {
    case TRIANGLE:
      Mesh::SetTriangleData(vertices, indices);
      break;
    case QUAD:
      Mesh::SetQuadData(vertices, indices);
      break;
    case CUBE:
      Mesh::SetCubeData(vertices, indices);
      break;
    case SPHERE:
      Mesh::SetSphereData(vertices, indices);
      break;
  }
  
  /* Vertex Array Object (VAO) */
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  
  /* Vertex Buffer Object (VBO) */
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), 
               &vertices[0], GL_STATIC_DRAW);
               
  /* Element Buffer Object */
  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), 
               &indices[0], GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
  glEnableVertexAttribArray(0);
  
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                       (void*)(offsetof(Vertex, Vertex::texCoords)));
  glEnableVertexAttribArray(1);  
  
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

MeshRenderer::~MeshRenderer() {
  
}

void MeshRenderer::Draw() {
  /* Translation Matrix */
  glm::mat4 translate = glm::translate(glm::mat4(1.0f), position);
  
  glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
  
  modelMatrix = translate * scaleMatrix;
  
  glm::mat4 vp = camera->GetProjectionMatrix() * camera->GetViewMatrix();
  
  glUseProgram(program);
  
  int vprojLoc = glGetUniformLocation(program, "vp");
  int modelLoc = glGetUniformLocation(program, "model");

  glUniformMatrix4fv(vprojLoc, 1, GL_FALSE, glm::value_ptr(vp));
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
  
  glBindTexture(GL_TEXTURE_2D, texture);
  
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
  
  glBindVertexArray(0);
}

void MeshRenderer::SetPosition(glm::vec3 _pos) {
  position = _pos;
}

void MeshRenderer::SetScale(glm::vec3 _scale) {
  scale = _scale;
}

void MeshRenderer::SetProgram(uint32_t _program) {
  program = _program;
}

void MeshRenderer::SetTexture(uint32_t _texture) {
  texture = _texture;
}