#include "Game.hpp"
#include "SDL_events.h"

Game::Game(const char *title, int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0 && IMG_Init(IMG_INIT_PNG)) {
    cout << "Initialized!" << endl;
    window = SDL_CreateWindow("EPS", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, width, height,
                              SDL_WINDOW_OPENGL);

    if (!window) {
      printf("Could not create window: %s\n", SDL_GetError());
      isRunning = false;
      return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
      printf("Could not create renderer: %s\n", SDL_GetError());
      isRunning = false;
      return;
    }

    backgroundImage = IMG_Load("assets/background.png");
    backgroundTex = SDL_CreateTextureFromSurface(renderer, backgroundImage);

    planet.setDest(300, 400, 200, 200);
    planet.setImage("assets/earth.png", renderer);
    planet.setSource(0, 0, 763, 383);

    player.setDest(385, 385, 30, 30);
    player.setImage("assets/spaceShip.png", renderer);
    player.setSource(0, 0, 212, 256);

    int planetHeight;
    int planetWidth;

    SDL_QueryTexture(planet.getTex(), NULL, NULL, &planetWidth, &planetHeight);

    cout << planetHeight << endl;

    isRunning = true;
  } else {
    isRunning = false;
  }
}

Game::~Game() {
  SDL_FreeSurface(backgroundImage);
  SDL_DestroyTexture(backgroundTex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}

void Game::update() {}

void Game::draw(Entity o) {
  SDL_Rect dest = o.getDest();
  SDL_Rect src = o.getSource();
  SDL_RenderCopyEx(renderer, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

void Game::render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, backgroundTex, NULL, NULL);
  draw(planet);
  draw(player);
  SDL_RenderPresent(renderer);
}

bool Game::running() { return isRunning; }
