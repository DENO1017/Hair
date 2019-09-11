#ifndef PARTICLE_H
#define PARTICLE_H

#include <stdlib.h>

#include <math.h>
using namespace std;

typedef unsigned long long sizetype;
struct cdn
{
    double x;
    double y;
};

class particle
{
public:
    particle();
    particle(cdn p,cdn s,int l){pos = p;speed= s;//weight = w;
                                      life = l;}
    cdn pos;
    cdn speed;
    cdn force;
    int weight;
    int life;
    void next(cdn f);
};

#endif // PARTICLE_H
