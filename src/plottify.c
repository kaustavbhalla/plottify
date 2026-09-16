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

void drawExpression(SDL_Surface *pSurface, const char *expr) {
  double x;
  te_variable vars[] = {{"x", &x}};

  int err;
  te_expr *pExpr = te_compile(expr, vars, 1, &err);

  if (pExpr) {
    for (x = X_START; x < X_END; x += STEP_SIZE) {
      double y = te_eval(pExpr);
    }
    double res = te_eval(pExpr);
    printf("Result: %lf\n", res);
  } else {
    fprintf(stderr, "Error evaluating expression: %s\n", expr);
    exit(-1);
  }
}
