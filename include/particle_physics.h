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

void updateParticleState(particle *pt_ptr, float t);
void printParticle(particle const *p);
void calculateGAcc(particle *p1, particle *p2);
