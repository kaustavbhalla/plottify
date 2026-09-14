#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <bits/posix2_lim.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *pWindow =
      SDL_CreateWindow("Function plotter", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_SHOWN);

  if (pWindow == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *pRenderer =
      SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
  if (pRenderer == NULL) {
    printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return 1;
  }

  SDL_Surface *pSurface = SDL_GetWindowSurface(pWindow);

  SDL_Rect rect = (SDL_Rect){50, 50, 50, 50};
  Uint32 color = 0xFF0000;
  SDL_FillRect(pSurface, &rect, color);

  bool isRunning = true;
  SDL_Event event;

  while (isRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        isRunning = false;
      }
    }

    SDL_UpdateWindowSurface(pWindow);
    SDL_SetRenderDrawColor(pRenderer, 30, 30, 30, 255);

    SDL_RenderClear(pRenderer);

    // 4. Present the drawn buffer to the screen (Crucial for Wayland mapping)
    SDL_RenderPresent(pRenderer);

    SDL_Delay(16);
  }

  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  SDL_Quit();

  return 0;
}
