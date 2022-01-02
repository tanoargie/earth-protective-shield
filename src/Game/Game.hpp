#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

class Game {

public:
  Game(const char *title, int width, int height);
  ~Game();

  void handleEvents();
  void update();
  void render();
  SDL_Renderer *getRenderer();

  bool running();

private:
  SDL_Renderer *renderer;
  SDL_Window *window;
  SDL_Surface *backgroundImage;
  SDL_Surface *planetImage;
  SDL_Texture *backgroundTex;
  SDL_Texture *planetTex;
  bool isRunning;
};

#endif
