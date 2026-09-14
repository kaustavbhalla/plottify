#include "plottify.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Hello plotter\n");

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *pWindow =
      SDL_CreateWindow("Math Expression Plotter", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

  if (pWindow == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Surface *pSurface = SDL_GetWindowSurface(pWindow);

  drawGrid(pSurface);

  SDL_Event event;
  bool app_running = true;

  while (app_running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        app_running = false;
      }
    }

    SDL_UpdateWindowSurface(pWindow);
    SDL_Delay(16);
  }

  // Clean up resources
  SDL_DestroyWindow(pWindow);
  SDL_Quit();

  return 0;
}
