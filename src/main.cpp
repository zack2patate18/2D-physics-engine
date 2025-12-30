#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include "Ball.hpp"

int main()
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
      "Physics Engine - By Zack", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_Event e;
  bool running = true;

  double speedSimulationMultiplier = 1;

  SDL_Color background_color = {73, 154, 191, 255};

  char ballName[] = "Ball 1";

  SDL_Color mainBallColor = {255, 0, 0, 255};

  Ball mainBall = Ball(500, 50, 20, mainBallColor, ballName, 9.81, renderer, true, true, background_color);

  const int FPS = 24;
  const int frameDelay = 1000 / FPS;

  Uint32 lastTime = SDL_GetTicks();
  double deltaTime = 0;

  bool applyNegativeYVel = false;
  bool applyPositiveYVel = false;
  bool applyNegativeXVel = false;
  bool applyPositiveXVel = false;

  while (running)
  {
    Uint32 frameStart = SDL_GetTicks();

    while (SDL_PollEvent(&e))
    {
      switch (e.type)
      {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (e.key.keysym.sym)
        {
        case SDLK_z:
          speedSimulationMultiplier *= 2;
          break;
        case SDLK_s:
          speedSimulationMultiplier /= 2;
          break;
        case SDLK_UP:
          applyNegativeYVel = true;
          break;
        case SDLK_DOWN:
          applyPositiveYVel = true;
          break;
        case SDLK_LEFT:
          applyNegativeXVel = true;
          break;
        case SDLK_RIGHT:
          applyPositiveXVel = true;
          break;
        }
        break;
      case SDL_KEYUP:
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
          applyNegativeYVel = false;
          break;
        case SDLK_DOWN:
          applyPositiveYVel = false;
          break;
        case SDLK_LEFT:
          applyNegativeXVel = false;
          break;
        case SDLK_RIGHT:
          applyPositiveXVel = false;
          break;
        }
      }
    }

    if (applyNegativeXVel)
      mainBall.applyXvelocity(-50);
    if (applyPositiveXVel)
      mainBall.applyXvelocity(50);
    if (applyNegativeYVel)
      mainBall.applyYvelocity(-50);
    if (applyPositiveYVel)
      mainBall.applyYvelocity(50);

    mainBall.update(deltaTime);

    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);
    SDL_RenderClear(renderer);
    mainBall.display();
    SDL_RenderPresent(renderer);

    Uint32 currentTime = SDL_GetTicks();
    deltaTime = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

    Uint32 frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime)
      SDL_Delay(frameDelay - frameTime);
  }

  SDL_Quit();
  return 0;
}
