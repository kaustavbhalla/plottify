#include "plottify.h"

void drawAtGridCoordinate(SDL_Surface *pSurface, double x, double y,
                          Uint32 color) {
  int xGrid = WIDTH / 2 + (x * (double)X_SCALE);
  int yGrid = HEIGHT / 2 - (y * (double)Y_SCALE);

  SDL_Rect newRect = (SDL_Rect){xGrid, yGrid, THICKNESS, THICKNESS};
  SDL_FillRect(pSurface, &newRect, color);
}

void drawGrid(SDL_Surface *pSurface) {
  for (double x = X_START; x < X_END; x += STEP_SIZE) {
    drawAtGridCoordinate(pSurface, x, 0, GRAY);
  }
  for (double y = Y_START; y < Y_END; y += STEP_SIZE) {
    drawAtGridCoordinate(pSurface, 0, y, GRAY);
  }
}

void drawExpression(SDL_Surface *pSurface, const char *expr) {
  double x;
  te_variable vars[] = {{"x", &x}};

  int err;
  te_expr *pExpr = te_compile(expr, vars, 1, &err);

  if (pExpr) {
    for (x = X_START; x < X_END; x += STEP_SIZE) {
      double y = te_eval(pExpr);
      drawAtGridCoordinate(pSurface, x, y, 0xFFFFFF);
    }
    double res = te_eval(pExpr);
    printf("Result: %lf\n", res);
  } else {
    fprintf(stderr, "Error evaluating expression: %s\n", expr);
    exit(-1);
  }
}
