#include "raylib.h"
#include <complex.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  InitWindow(300, 200, "asd");
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
	//
  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
