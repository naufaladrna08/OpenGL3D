#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <App.h>
#include <Shader.h>
#include <Camera.h>
#include <LightRenderer.h>
#include <MeshRenderer.h>
#include <TextureLoader.h>
using namespace std;
GLFWwindow* window;
Camera* camera = new Camera(45.0f, WIDTH, HEIGHT, 0.1f, 100.0f, 
                            glm::vec3(0.0f, 0.0f, 6.0f));;
MeshRenderer* cube[10];

/* New */
float deltaTime = 0.0f;
float lastFrame = 0.0f;

float lastX = WIDTH / 2.0f;
float lastY = HEIGHT / 2.0f;
bool firstMouse = true;

float yaw = -90.0f, pitch;

void processInput(GLFWwindow* win) {
  float speed = 2.0f * deltaTime;
  
  if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS)
    camera->ProcessKeyboard(UP, speed);
  if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS)
    camera->ProcessKeyboard(DOWN, speed);
  if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS)
    camera->ProcessKeyboard(LEFT, speed);
  if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS)
    camera->ProcessKeyboard(RIGHT, speed);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }
  
  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos;
  lastX = xpos;
  lastY = ypos;
  
  float sen = 0.1f;
  xoffset *= sen;
  yoffset *= sen;
  
  pitch += yoffset;
  yaw   += xoffset;
  
  
  if(pitch > 89.0f)
    pitch =  89.0f;
  if(pitch < -89.0f)
    pitch = -89.0f;
    
  camera->ProcessMouse(yaw, pitch);
}
/* End of new */

int main(int argc, char* argv[]) {
  /* Init GLFW */
  if (!glfwInit()) {
    cout << "Failed to initialize GLFW" << endl;
    return -1;
  }
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  window = glfwCreateWindow(WIDTH, HEIGHT, APP_NAME, NULL, NULL);
  
  /* Make GLFW Context */
  glfwMakeContextCurrent(window);
  
  /* Init GLAD */
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    cout << "Failed to initialize GLEW" << endl;
    
    /* Ga mau jalannin kalau OpenGL ga ke load */
    glfwTerminate();
    return -1;
  }
  
  glfwSetCursorPosCallback(window, mouse_callback);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  
  glEnable(GL_DEPTH_TEST);
  
  Shader shader("../assets/shaders/Basic.vs",
                "../assets/shaders/Basic.fs");
               
  TextureLoader texture;
  GLuint program = shader.GetProgram();
  GLuint tex = texture.GetTextureID("../assets/libre.png");
  
  for (int i = 0; i < 10; i++) {
    cube[i] = new MeshRenderer(CUBE, camera);
    cube[i]->SetProgram(program);
    cube[i]->SetTexture(tex);
    cube[i]->SetPosition(glm::vec3((float) i, 0.0f, 0.0f));
    cube[i]->SetScale(glm::vec3(0.5f));
  }
  
  /* Game loop */
  while (!glfwWindowShouldClose(window)) {
    /* New */
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    /* End of new */
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 1.0f, 1.0f);
    
    for (int i = 0; i < 10; i++) {
      cube[i]->Draw();
    }
    
    processInput(window);
    
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}