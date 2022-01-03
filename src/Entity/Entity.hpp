#ifndef Entity_hpp
#define Entity_hpp

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

class Entity {
private:
  SDL_Rect dest;
  SDL_Rect src;
  SDL_Texture *tex;
  bool solid;
  int id;

public:
  Entity() { solid = 1; }
  SDL_Rect getDest() const { return dest; }
  SDL_Rect getSource() const { return src; }
  void setDest(int x, int y, int w, int h);
  void setDest(int x, int y);
  void setSource(int x, int y, int w, int h);
  void setImage(string filename, SDL_Renderer *ren);
  SDL_Texture *getTex() const { return tex; }
  void setSolid(bool s) { solid = s; }
  bool getSolid() const { return solid; }
  int getDX() const { return dest.x; }
  int getDY() const { return dest.y; }
  int getDW() const { return dest.w; }
  int getDH() const { return dest.h; }
  void setId(int i) { id = i; }
  int getId() const { return id; }
};
#endif
