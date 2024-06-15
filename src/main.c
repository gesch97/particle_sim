#include "raylib.h"
#include <complex.h>
#include <particle_physics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawParticle(const particle *restrict pt_ptr) {
  DrawCircle(pt_ptr->x, pt_ptr->y, pt_ptr->r, BLACK);
}

int main(int argc, char *argv[]) {
  InitWindow(1200, 900, "Particle Simulator");
  SetTargetFPS(120); // Set our game to run at 60 frames-per-second
  particle pt1 = {
      .r = 5,
      .x = 600,
      .y = 600,
      .xv = 5,
      .yv = 0,
      .xa = 0,
      .ya = 6,
      .m = 10000,
  };
  particle pt2 = {
      .r = 5,
      .x = 600,
      .y = 650,
      .xv = -5,
      .yv = 0,
      .xa = 0,
      .ya = 0,
      .m = 10000,
  };

  // Main game loop
  clock_t last_time = clock();
  double elapsed_time;
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    elapsed_time = ((double)(clock() - last_time)) * 0.0001;
    last_time = clock();

    // Update clock
    calculateGAcc(&pt1, &pt2);
    updateParticleState(&pt1, elapsed_time);
    updateParticleState(&pt2, elapsed_time);
    printParticle(&pt1);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawParticle(&pt1);
    drawParticle(&pt2);

    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
