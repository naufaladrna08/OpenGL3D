#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glad/glad.h>
using namespace std;

/**
 * @class Shader
 * @author Naufal Adriansyah
 * @date 18/06/21
 * @file Shader.h
 * @brief Class for Shader Creation.
 */
class Shader {
public:
  Shader(const char* vertexSource, const char* fragmentSource);
  ~Shader();
  
  void Use();
  void Unuse();
  
  void CompileShader(string vertex_shader, string fragment_shader);
  
  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
  
  unsigned int GetProgram();

private:
  unsigned int m_vertexShader, m_fragmentShader, m_shaderProgram;
};

#endif