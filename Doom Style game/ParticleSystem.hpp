#pragma once
#include <vector>

struct Particle
{
    double x, y;
    double vx, vy;
    float life;
};

class ParticleSystem
{
public:
    std::vector<Particle> list;

    void spawn(double x, double y, double vx, double vy, float life = 1.0f);
    void update(float dt);
};