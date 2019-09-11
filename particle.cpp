#include "particle.h"

particle::particle()
{
    cdn t;
    t.x=380;
    t.y=150;
    pos = t;
    cdn s;
    s.x = -13+rand()%26;
    s.y = -25+rand()%10;
    speed = s;
    cdn f;
    f.x = 0;
    f.y = 5;
    force = f;
    weight=10+rand()%20;
    life=12;
}

void particle::next(cdn f)
{
    pos.x+=speed.x;
    pos.y+=speed.y;
    double rotate=1;
//    if(f.y!=0&&speed.y!=0)
//        rotate = 1;
//    else {
//        rotate = 0;
//    }
    speed.x+=force.x+rotate*(f.x/weight);
    speed.y+=force.y+rotate*(f.y/weight);
    weight--;
    life--;
}
