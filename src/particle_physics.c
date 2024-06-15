#include <math.h>
#include <particle_physics.h>
#include <stdio.h>

void updateParticleState(particle *pt_ptr, float t) {
  pt_ptr->x += pt_ptr->xv * t + 0.5f * pt_ptr->xa * t * t;
  pt_ptr->y += pt_ptr->yv * t + 0.5f * pt_ptr->ya * t * t;
  pt_ptr->xv += pt_ptr->xa * t;
  pt_ptr->yv += pt_ptr->ya * t;
}

void printParticle(particle const *p) {
  printf("(x,y) = (%f,%f)\n", p->x, p->y);
  printf("(xv,yv) = (%f,%f)\n", p->xv, p->yv);
  printf("(xa,ya) = (%f,%f)\n", p->xa, p->ya);
}

void calculateGAcc(particle *p1, particle *p2) {
  const float dx = p1->x - p2->x;
  const float dy = p1->y - p2->y;
  const double r2 = dx * dx + dy * dy;
  const double r = sqrt(r2);

  p1->xa = -p2->m * dx / r2 / r;
  p1->ya = -p2->m * dy / r2 / r;

  p2->xa = p1->m * dx / r2 / r;
  p2->ya = p1->m * dy / r2 / r;
}
