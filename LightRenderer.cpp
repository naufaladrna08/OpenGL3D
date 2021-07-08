#include <LightRenderer.h>

LightRenderer::LightRenderer(MeshType meshType, Camera* cam) {
  this->camera = cam;
  
  switch (meshType) {
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
  
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                       (void*)(offsetof(Vertex, Vertex::color)));
  glEnableVertexAttribArray(1);  
  
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

LightRenderer::~LightRenderer() {
  
}
  
void LightRenderer::Draw() {
  /* Model, view and projection matrix */
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(glm::mat4(1.0f), position);

  glUseProgram(this->program);
  
  int modelLoc = glGetUniformLocation(program, "model");
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
  
  glm::mat4 view = camera->GetViewMatrix();
  glm::mat4 proj = camera->GetProjectionMatrix();

  int viewLoc = glGetUniformLocation(program, "view");
  int projLoc = glGetUniformLocation(program, "projection");

  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
  
  glBindVertexArray(0);
  glUseProgram(0);
}
  
void LightRenderer::SetPosition(glm::vec3 _position) {
  position = _position;
}


void LightRenderer::SetColor(glm::vec3 _color) {
  this->color = _color;
}

void LightRenderer::SetProgram(GLuint _program) {
  this->program = _program;
}
  
glm::vec3 LightRenderer::GetPosition() {
  return position;
}

glm::vec3 LightRenderer::GetColor() {
  return color;
}