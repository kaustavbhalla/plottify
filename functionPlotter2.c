#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 600

void drawAtGridCoordinate(SDL_Surface *pSurface, SDL_Rect *pRect,
                          Uint32 color) {
  int xGrid = WIDTH / 2 + pRect->x;
  int yGrid = HEIGHT / 2 - pRect->y;

  SDL_Rect newRect = (SDL_Rect){xGrid, yGrid, pRect->w, pRect->h};
  SDL_FillRect(pSurface, &newRect, color);
}

void drawGrid(SDL_Surface *pSurface) {
  Uint32 color = 0xFF0000;
  SDL_Rect *pRect = malloc(sizeof(SDL_Rect *));

  for (int i = -WIDTH / 2; i < WIDTH / 2; i++) {
    pRect->h = 1;
    pRect->w = 1;

    pRect->x = i;
    pRect->y = HEIGHT / 2;
    drawAtGridCoordinate(pSurface, pRect, color);
  }
}

int main() {
  printf("Hello plotter\n");

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *pWindow =
      SDL_CreateWindow("Math Expression Plotter", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_SHOWN);

  if (pWindow == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Surface *pSurface = SDL_GetWindowSurface(pWindow);

  Uint32 color = SDL_MapRGB(pSurface->format, 255, 0, 0);
  SDL_Rect rect = {50, 50, 50, 50};

  // SDL_FillRect(pSurface, &rect, color);

  drawGrid(pSurface);

  // drawAtGridCoordinate(pSurface, &rect, color);

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

  // 4. Clean up resources
  SDL_DestroyWindow(pWindow);
  SDL_Quit();

  return 0;
}
