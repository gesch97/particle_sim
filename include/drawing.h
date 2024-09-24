#pragma once
#include "raylib.h"
#include <particle_physics.h>
#include <stdio.h>

enum axis { X, Y };

void drawParticles(particle p[], size_t p_s);
void drawArrowAlongAxis(int x, int y, int height, enum axis ax);
