#include "grass.h"

Grass::Grass()
{

    // Random nummer mellan -10 och 10
    float xpos = 20.0*(rand()/float(RAND_MAX)) - 10.0;
    float zpos = 20.0*(rand()/float(RAND_MAX)) - 10.0;

    base[0] = xpos;
    base[1] = 0.0f;
    base[2] = zpos;

    theta0 = 90 + 20.0*(rand()/float(RAND_MAX)) - 10.0;
    theta = theta0;

    radius1 = 1.8f;
    K = 2.0f;
    inertia = 1.0f;

}

Grass::Grass(float x, float z)
{
    base[0] = x;
    base[1] = 0.0f;
    base[2] = z;

    theta0 = 90 + 40.0*(rand()/float(RAND_MAX)) - 20.0;
    theta = theta0;
    omega = 0;

    radius1 = 1.8f;
    K = 2.0f;
    inertia = 1.0f;
}

Grass::~Grass()
{
    delete base;
}

void Grass::calculate(Vector3f wind, float deltaT)
{
    Vector3f position = -Vector3f(radius1*cos(DEG2RAD(theta)), radius1*sin(DEG2RAD(theta)), 0);
    Vector3f F = (wind+Vector3f(0.0, -9.82, 0.0));

    float alpha = M_PI/2 - acos(position.dotProduct(F)/(position.length()*F.length()));

    float Fr = F.length()*cos(alpha);

    float tau = radius1*Fr - K*(theta - theta0);
    omega = omega + (1/inertia)*tau*deltaT;
    omega *= 0.9999;
    theta = theta + omega*deltaT;
}

void Grass::draw()
{
    glBegin(GL_LINES);
        glVertex3f(base[0], base[1], base[2]);
        glVertex3f(base[0] + radius1*cos(theta*(3.14159f/180.0f)), base[1] + radius1*sin(theta*(3.14159f/180.0f)), base[2]);
    glEnd();

    /*glBegin(GL_LINES);
        glColor3f(1.0,1.0,0.0);
        glVertex3f(base[0], base[1], base[2]);
        glVertex3f(base[0] + radius1*cos(theta0*(3.14159f/180.0f)), base[1] + radius1*sin(theta0*(3.14159f/180.0f)), base[2]);
    glEnd();*/
}
