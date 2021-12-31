#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <stdlib.h>

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {
  SDL_Window *window; // Declare a pointer
  SDL_Renderer *renderer = NULL;
  SDL_Texture *bitmapTex = NULL;
  SDL_Texture *bitmapTexEarth = NULL;
  SDL_Surface *bitmapSurface = NULL;
  SDL_Surface *earth = NULL;
  SDL_Rect destination;

  SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2
  IMG_Init(IMG_INIT_PNG);

  // Create an application window with the following settings:
  window = SDL_CreateWindow("Earch Protective Shield", // window title
                            SDL_WINDOWPOS_UNDEFINED,   // initial x position
                            SDL_WINDOWPOS_UNDEFINED,   // initial y position
                            SCREEN_WIDTH,              // width, in pixels
                            SCREEN_HEIGHT,             // height, in pixels
                            SDL_WINDOW_OPENGL          // flags - see below
  );

  // Check that the window was successfully created
  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  bitmapSurface = IMG_Load("assets/background.png");
  earth = IMG_Load("assets/earth.png");
  bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
  bitmapTexEarth = SDL_CreateTextureFromSurface(renderer, earth);
  SDL_FreeSurface(bitmapSurface);
  SDL_FreeSurface(earth);
  // The window is open: could enter program loop here (see SDL_PollEvent())
  SDL_Event e;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
      if (e.type == SDL_KEYDOWN) {
        quit = true;
      }
      if (e.type == SDL_MOUSEBUTTONDOWN) {
        quit = true;
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
    SDL_RenderCopy(renderer, bitmapTexEarth, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  // Close and destroy the window
  SDL_DestroyTexture(bitmapTex);
  SDL_DestroyTexture(bitmapTexEarth);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  // Clean up
  IMG_Quit();
  SDL_Quit();

  return 0;
}
