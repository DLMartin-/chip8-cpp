#include <SDL3/SDL_init.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL_video.h>
#include <iostream>
#include <SDL3/SDL.h>

int main (int argc, char *argv[])
{
  if(SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "Could not initialize SDL3\n";
    std::cout << SDL_GetError();
    std::cout <<"\n";
    return -1;
  }
  auto const window = SDL_CreateWindow("Chip8-Cpp", 380, 120, 0);
  if(window == nullptr) {
    std::cout << "Could not create window!\n" << SDL_GetError() << "\n";
    return -1;
  }
  auto const renderer = SDL_CreateRenderer(window, nullptr, 0);
  if(renderer == nullptr) {
    std::cout << "Could not  create renderer!\n" << SDL_GetError() << "\n";
    return -1;
  }

  SDL_Event event{};
  while(true) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) return 0;
    }

    SDL_SetRenderDrawColor(renderer,255, 0, 255, 0x00);
    //SDL_SetRenderDrawColor(renderer,255, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
