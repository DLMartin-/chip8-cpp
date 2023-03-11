#include <SDL.h>
#include <cstdlib>

#include "src/emulator_main.h"

bool initialize_sdl() noexcept;

auto main (int argc, char *argv[]) -> int
{
  if(initialize_sdl() == false) return -1;

  return emulator_main(argc, argv);
}

[[nodiscard]]
bool initialize_sdl() noexcept {
  constexpr auto flags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
  return SDL_Init(flags) == 0 && std::atexit(SDL_Quit) == 0;
}

