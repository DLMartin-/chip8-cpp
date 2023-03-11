#include <SDL_video.h>
#include <cstdlib>
#include <SDL.h>
#include <optional>
#include <iostream>

#include "src/emulator_main.h"

SDL_Window* window;
SDL_Renderer* renderer;

auto main(int argc, char *argv[]) -> int {
  std::optional<EmulatorArgs> initialize_sdl() noexcept;
  void register_atexit() noexcept;

  auto args = initialize_sdl();
  if(!args.has_value()) {
    std::cout << SDL_GetError() << "\n There was an error :(\n";
    return -1;
  }

  return emulator_main(args.value());
}

void register_atexit() noexcept {
  constexpr auto at_exit = [](){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  };
  std::atexit(at_exit);
}

[[nodiscard]] std::optional<EmulatorArgs> initialize_sdl() noexcept {
  register_atexit();

  constexpr auto flags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
  if(SDL_Init(flags) != 0) {
    std::cout << "Could not initialize SDL\n";
    return std::nullopt;
  } 

  if(window = SDL_CreateWindow("Chip8-Cpp", 400, 200, 0); !window){
    std::cout << "Could not create a window \n";
    return std::nullopt;}
  if(renderer = SDL_CreateRenderer(window, nullptr, 0); !renderer){
    std::cout << "Could not create a renderer\n";
    return std::nullopt;
  }

  return EmulatorArgs{window, renderer};
}

