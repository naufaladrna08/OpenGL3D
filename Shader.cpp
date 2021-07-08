#include <Shader.h>

Shader::Shader(const char* vertexSource, const char* fragmentSource) {
  ifstream file;
  stringstream vertex, fragment;
  string line;
  
  /* Vertex Shader */
  file.open(vertexSource);
  if (file.is_open()) {
    while (getline(file, line)) {
      vertex << line << endl;
    }
    
    file.close();
  } else {
    cout << "Vertex shader not found!" << endl;
  }
  
  /* Fragment Shader */
  file.open(fragmentSource);
  if (file.is_open()) {
    while (getline(file, line)) {
      fragment << line << endl;
    }
    
    file.close();
  } else {
    cout << "Fragment shader not found!" << endl;
  }
  
  CompileShader(vertex.str(), fragment.str());
  
  glDeleteShader(m_vertexShader);
  glDeleteShader(m_fragmentShader);
}

Shader::~Shader() {
  
}
  
void Shader::Use() {
  glUseProgram(m_shaderProgram);
}

void Shader::Unuse() {
  glUseProgram(0);
}
  
void Shader::CompileShader(string vertex_shader, string fragment_shader) {
  const char* vertex   = vertex_shader.c_str();
  const char* fragment = fragment_shader.c_str();
  /* Vertex Shader */
  m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(m_vertexShader, 1, &vertex, NULL);
  glCompileShader(m_vertexShader);
  
  int success;
  char infoLog[512];
  
  glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(m_vertexShader, 512, NULL, infoLog);
    cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
  }
  
  /* Fragment Shader */
  m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(m_fragmentShader, 1, &fragment, NULL);
  glCompileShader(m_fragmentShader);
  
  glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(m_fragmentShader, 512, NULL, infoLog);
    cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
  }
  
  /* Shader Program */
  m_shaderProgram = glCreateProgram();
  glAttachShader(m_shaderProgram, m_vertexShader);
  glAttachShader(m_shaderProgram, m_fragmentShader);
  glLinkProgram(m_shaderProgram);
}

void Shader::setBool(const std::string &name, bool value) const {
  glUniform1i(glGetUniformLocation(m_shaderProgram, name.c_str()), (int)value); 
}

void Shader::setInt(const std::string &name, int value) const {
  glUniform1i(glGetUniformLocation(m_shaderProgram, name.c_str()), value); 
}

void Shader::setFloat(const std::string &name, float value) const {
  glUniform1f(glGetUniformLocation(m_shaderProgram, name.c_str()), value); 
}

unsigned int Shader::GetProgram() {
  return m_shaderProgram;
}