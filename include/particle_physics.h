#pragma once
#include <stdio.h>

typedef struct {
  int r;
  float x;
  float y;
  double xv;
  double yv;
  double xa;
  double ya;
  float m;
} particle;

void updateParticlesState(particle p[], size_t p_s, float t);
void printParticle(particle const *p);
void calculateGAcc(particle p[], size_t p_s);
void setAccToZero(particle p[], size_t p_s);

