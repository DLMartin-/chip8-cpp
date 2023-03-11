#include "emulator_main.h"

#include <SDL.h>
#include <SDL_error.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <iostream>
#include <optional>

struct SdlRenderingContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
};
std::optional<SdlRenderingContext> create_window_and_renderer() noexcept;

int emulator_main(int argc, char **argv) noexcept {

  auto const rendering_context = create_window_and_renderer();
  if (rendering_context == std::nullopt)
    return -1;

  auto const [window, renderer] = rendering_context.value();
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

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  return 0;
}

[[nodiscard]] std::optional<SdlRenderingContext>
create_window_and_renderer() noexcept {
  SDL_Window *window = SDL_CreateWindow("Chip8-Cpp", 380, 100, 0);
  if (window == nullptr) {
    std::cout << "Could not create an SDL Window!\n";
    std::cout << "Error: " << SDL_GetError() << "\n";
    return std::nullopt;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr, 0);
  if (renderer == nullptr) {
    std::cout << "Could not create an SDL Renderer!\n";
    std::cout << "Error: " << SDL_GetError() << "\n";
    SDL_DestroyWindow(window);
    return std::nullopt;
  }

  return SdlRenderingContext{window, renderer};
}
