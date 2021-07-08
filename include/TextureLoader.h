#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <string>
#include <glad/glad.h>
using namespace std;

class TextureLoader {
public:
  TextureLoader();
  ~TextureLoader();
  
  uint32_t GetTextureID(string loc);
};

#endif