#include <complex.h>
#include <drawing.h>
#include <stdlib.h>

#define ARROW_COLOR BLACK
#define ARROW_WIDTH 3

void drawParticles(particle p[], size_t p_s) {
  for (size_t i = 0; i < p_s; i++) {
    DrawCircle(p[i].x, p[i].y, p[i].r, BLACK);
  }
}

void drawArrowAlongAxis(int x, int y, int height, enum axis ax) {
  Vector2 v1, v2, v3;
  Vector2 rectP, rectS;
  if (ax == X) {
  } else if (ax == Y) {
    rectP = (Vector2){.x = x, .y = y};
    rectS = (Vector2){.x = ARROW_WIDTH, .y = height};
  } else {
    exit(EXIT_FAILURE);
  }
  DrawTriangle(v1, v2, v3, ARROW_COLOR);
  DrawRectangleV(rectP, rectS, BLACK);
}
