#include "raylib.h"
#include <complex.h>
#include <particle_physics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawParticle(const particle *restrict pt_ptr) {
  DrawCircle(pt_ptr->x, pt_ptr->y, pt_ptr->r, BLACK);
}
#define NO_OF_PTS 3
int main(int argc, char *argv[]) {
  InitWindow(1200, 900, "Particle Simulator");
  SetTargetFPS(120); // Set our game to run at 60 frames-per-second
  particle pts[NO_OF_PTS];
  pts[0] = (particle){
      .r = 5,
      .x = 500,
      .y = 500,
      .xv = -40,
      .yv = 0,
      .xa = 0,
      .ya = 6,
      .m = 100,
  };
  pts[1] = (particle){
      .r = 5,
      .x = 300,
      .y = 300,
      .xv = 40,
      .yv = 0,
      .xa = 0,
      .ya = 0,
      .m = 100,
  };
  pts[2] = (particle){
      .r = 10,
      .x = 400,
      .y = 400,
      .xv = 0,
      .yv = 0,
      .xa = 0,
      .ya = 0,
      .m = 100000,
  };
  clock_t last_time = clock();
  double elapsed_time;
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    elapsed_time = ((double)(clock() - last_time)) * 0.00001;
    last_time = clock();

    setAccToZero(&pts[0]);
    setAccToZero(&pts[1]);
    setAccToZero(&pts[2]);
    for (size_t i = 0; i < NO_OF_PTS; i++) {
      for (size_t j = i + 1; j < NO_OF_PTS; j++) {
        calculateGAcc(&pts[i], &pts[j]);
      }
    }
    updateParticleState(&pts[0], elapsed_time);
    updateParticleState(&pts[1], elapsed_time);
    updateParticleState(&pts[2], elapsed_time);
    printParticle(&pts[0]);

    BeginDrawing();

    DrawFPS(GetScreenWidth() - 100, GetScreenHeight() - 50);

    ClearBackground(RAYWHITE);
    drawParticle(&pts[0]);
    drawParticle(&pts[1]);
    drawParticle(&pts[2]);

    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
