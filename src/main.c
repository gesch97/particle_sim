#include "raylib.h"
#include <complex.h>
#include <particle_physics.h>
#include <stdlib.h>
#include <time.h>

void drawParticles(particle p[], size_t p_s) {
  for (size_t i = 0; i < p_s; i++) {
    DrawCircle(p[i].x, p[i].y, p[i].r, BLACK);
  }
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

    setAccToZero(pts, NO_OF_PTS);
    calculateGAcc(pts, NO_OF_PTS);

    updateParticlesState(pts, NO_OF_PTS, elapsed_time);
    printParticle(&pts[0]);

    BeginDrawing();

    DrawFPS(GetScreenWidth() - 100, GetScreenHeight() - 50);

    ClearBackground(RAYWHITE);
    drawParticles(pts, NO_OF_PTS);

    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
