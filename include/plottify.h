#ifndef PLOTTIFY_H
#define PLOTTIFY_H

#include "tinyexpr.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#define WIDTH 900
#define HEIGHT 600
#define GRAY 0x303030
#define X_START -10
#define X_END 10
#define Y_START -5
#define Y_END 5
#define STEP_SIZE 0.1

#define X_SCALE WIDTH / (X_END - X_START)
#define Y_SCALE HEIGHT / (Y_END - Y_START)

#define THICKNESS 2
void drawAtGridCoordinate(SDL_Surface *pSurface, double x, double y,
                          Uint32 color);
void drawGrid(SDL_Surface *pSurface);
void drawExpression(SDL_Surface *pSurface, const char *expr);
#endif
