#ifndef HAIR_H
#define HAIR_H

#include "particle.h"
#include <vector>

using namespace std;

class hair
{
public:
    particle par;
    vector<cdn> hpar;

    hair();
    particle init();
    void next(cdn f,hair ori);
};

#endif // HAIR_H
