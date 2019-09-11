#include "hair.h"

hair::hair()
{
    par = particle();
    particle mid = par;
    cdn f;
    f.x=0;
    f.y=0;
    while(mid.life>0)
    {
        hpar.push_back(mid.pos);
        mid.next(f);
    }
}

particle hair::init()
{
    cdn p;
    p.x=300;
    p.y=350;
    cdn spd;
    spd.x=3;
    spd.y=5;
    return (particle(p,spd,20));
}

void hair::next(cdn f,hair ori)
{
    particle mid = par;
    for(sizetype i=0;i<hpar.size();i++)
    {
        hpar[i]=mid.pos;
        mid.next(f);
    }
}

