#include <math.h>
#include <particle_physics.h>
#include <stdio.h>

void updateParticlesState(particle p[], size_t p_s, float t) {

  for (size_t i = 0; i < p_s; i++) {
    p[i].x += p[i].xv * t + 0.5f * p[i].xa * t * t;
    p[i].y += p[i].yv * t + 0.5f * p[i].ya * t * t;
    p[i].xv += p[i].xa * t;
    p[i].yv += p[i].ya * t;
  }
}

void printParticle(particle const *p) {
  printf("(x,y) = (%f,%f)\n", p->x, p->y);
  printf("(xv,yv) = (%f,%f)\n", p->xv, p->yv);
  printf("(xa,ya) = (%f,%f)\n", p->xa, p->ya);
}

void calculateGAcc(particle p[], size_t p_s) {
  for (size_t i = 0; i < p_s; i++) {
    for (size_t j = i + 1; j < p_s; j++) {
      const float dx = p[i].x - p[j].x;
      const float dy = p[i].y - p[j].y;
      const double r2 = dx * dx + dy * dy;
      const double r = sqrt(r2);

      p[i].xa += -p[j].m * dx / r2 / r;
      p[i].ya += -p[j].m * dy / r2 / r;

      p[j].xa += p[i].m * dx / r2 / r;
      p[j].ya += p[i].m * dy / r2 / r;
    }
  }
}

void setAccToZero(particle p[], size_t p_s) {
  for (size_t i = 0; i < p_s; i++) {
    p[i].xa = 0;
    p[i].ya = 0;
  }
}
