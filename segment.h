

// Grass segment
#ifndef __SEGMENT__
#define __SEGMENT__

#include "vmath.h"

class Segment
{
private:
    Vector3f position;
    float inertia;
    float springConstant;
    float length;
    float mass;
    float angle;
    float angularVelocity;


public:
    Segment();
    Segment(const Vector3f &parent, float parentAngle, float theLength = 0.3f);
    void init(const Vector3f &parent, float parentAngle, float theLength);
    void calculatePosition(const Vector3f &wind, const Vector3f &parent, float parentAngle, double timestep);
    Vector3f getPosition();
    float getAngle();
};


#endif
