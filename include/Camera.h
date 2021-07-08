#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h> /// new
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/* DEBUGGING */
#include <iostream>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
using namespace std;

enum {
  LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3
};

class Camera {
public:
  Camera(GLfloat FOV, GLfloat width, GLfloat height, GLfloat near, GLfloat far,
         glm::vec3 camPos);
  ~Camera();
  
  void ProcessKeyboard(int direction, float speed); /// new
  void ProcessMouse(float yaw, float pitch);
  
  glm::mat4 GetViewMatrix();  
  glm::mat4 GetProjectionMatrix();
  glm::vec3 GetCamPosition();
  
private:
  glm::mat4 viewMatrix;
  glm::mat4 projectionMatrix;
  glm::vec3 cameraPos, cameraFront, cameraUp;

};

#endif 