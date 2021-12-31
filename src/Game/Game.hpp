#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

class Game {

public:
  Game();
  ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running();

private:
  SDL_Renderer *renderer;
  SDL_Window *window;
  SDL_Surface *backgroundImage;
  SDL_Texture *background;
  bool isRunning;
};

#endif
