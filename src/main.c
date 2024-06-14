#include "raylib.h"
#include <complex.h>
#include <stdlib.h>

typedef struct {
  float r;
  float x;
  float y;
} particle;

void drawParticle(particle *pt_ptr) { ; }

int main(int argc, char *argv[]) {
  InitWindow(1000, 700, "asd");
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  particle pt1 = {
      .r = 2,
      .x = 5,
      .y = 5,
  };

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircle(pt1.x, pt1.y, pt1.r, DARKBLUE);

    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
