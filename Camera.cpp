#include <Camera.h>

Camera::Camera(GLfloat FOV, GLfloat width, GLfloat height, GLfloat near, GLfloat far,
         glm::vec3 camPos) {
  cameraPos = camPos;
  
  cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
  cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
  
  viewMatrix        = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
  projectionMatrix  = glm::perspective(FOV, width / height, near, far);
}

Camera::~Camera() {
  
}

void Camera::ProcessKeyboard(int direction, float speed) {
  if (direction == UP) {
    cameraPos += speed * cameraFront;
    cout << to_string(cameraPos) << endl;
  }
  if (direction == DOWN)
    cameraPos -= speed * cameraFront;
  if (direction == LEFT)
    cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
  if (direction == RIGHT)
    cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
}

void Camera::ProcessMouse(float yaw, float pitch) {
  glm::vec3 dir;
  
  dir.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
  dir.y = glm::sin(glm::radians(pitch));
  dir.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
  cameraFront = glm::normalize(dir);
}
  
glm::mat4 Camera::GetViewMatrix() {
  return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

glm::mat4 Camera::GetProjectionMatrix() {
  return projectionMatrix;
}

glm::vec3 Camera::GetCamPosition() {
  return cameraPos;
}