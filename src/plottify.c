#include "plottify.h"

void drawAtGridCoordinate(SDL_Surface *pSurface, SDL_Rect *pRect,
                          Uint32 color) {
  int xGrid = WIDTH / 2 + pRect->x;
  int yGrid = HEIGHT / 2 - pRect->y;

  SDL_Rect newRect = (SDL_Rect){xGrid, yGrid, pRect->w, pRect->h};
  SDL_FillRect(pSurface, &newRect, color);
}

void drawGrid(SDL_Surface *pSurface) {
  SDL_Rect xAxis;
  xAxis.x = -(WIDTH) / 2;
  xAxis.y = 0;
  xAxis.w = WIDTH;
  xAxis.h = 2;
  drawAtGridCoordinate(pSurface, &xAxis, GRAY);

  SDL_Rect yAxis;
  yAxis.y = HEIGHT / 2;
  yAxis.x = 0;
  yAxis.w = 2;
  yAxis.h = HEIGHT;
  drawAtGridCoordinate(pSurface, &yAxis, GRAY);
}
