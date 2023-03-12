#include <SDL.h>
#include "rom.h"

struct EmulatorArgs {
  SDL_Window* window;
  SDL_Renderer* renderer;
};

int emulator_main(EmulatorArgs args, Rom const& rom) noexcept;

