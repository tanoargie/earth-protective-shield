#include "Entity.hpp"

void Entity::setDest(int x, int y, int w, int h) {
  dest.x = x;
  dest.y = y;
  dest.w = w;
  dest.h = h;
}

void Entity::setDest(int x, int y) {
  dest.x = x;
  dest.y = y;
}

void Entity::setSource(int x, int y, int w, int h) {
  src.x = x;
  src.y = y;
  src.w = w;
  src.h = h;
}

void Entity::setImage(string filename, SDL_Renderer *ren) {
  tex = IMG_LoadTexture(ren, filename.c_str());
}
