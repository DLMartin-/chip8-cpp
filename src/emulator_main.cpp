#include "emulator_main.h"

#include <SDL.h>
#include <SDL_error.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <iostream>
#include <optional>

int emulator_main(EmulatorArgs args, Rom const& rom) noexcept {
  auto const [window, renderer] = args;
  SDL_Event event{};
  while (true) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        return 0;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  return 0;
}

