#ifndef PLOTTIFY_H
#define PLOTTIFY_H

#include "tinyexpr.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#define WIDTH 900
#define HEIGHT 600
#define GRAY 0x303030

void drawAtGridCoordinate(SDL_Surface *pSurface, SDL_Rect *pRect, Uint32 color);
void drawGrid(SDL_Surface *pSurface);
void drawExpression(SDL_Surface *pSurface, const char *expr);
#endif
