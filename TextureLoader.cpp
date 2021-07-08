#include <TextureLoader.h>
#define STB_IMAGE_IMPLEMENTATION
#include <STBImage.h>

TextureLoader::TextureLoader() {
  
}

TextureLoader::~TextureLoader() {
  
}
  
uint32_t TextureLoader::GetTextureID(string loc) {
  int width, height, channel;
  
  stbi_uc* image = stbi_load(loc.c_str(), &width, &height, &channel, STBI_rgb);
  
  uint32_t mtexture;
  glGenTextures(1, &mtexture);
  glBindTexture(GL_TEXTURE_2D, mtexture);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, 
               GL_UNSIGNED_BYTE, image);
               
  glGenerateMipmap(GL_TEXTURE_2D);
  
  glBindTexture(GL_TEXTURE_2D, 0);
  stbi_image_free(image);
  
  return mtexture;
}