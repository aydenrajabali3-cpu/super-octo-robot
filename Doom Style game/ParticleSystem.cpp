#include "ParticleSystem.hpp"
#include <algorithm>

void ParticleSystem::spawn(double x, double y, double vx, double vy, float life)
{
    list.push_back({ x, y, vx, vy, life });
}

void ParticleSystem::update(float dt)
{
    for (auto& p : list)
    {
        p.x += p.vx * dt;
        p.y += p.vy * dt;
        p.life -= dt;
    }

    list.erase(std::remove_if(list.begin(), list.end(),
        [](Particle& p) { return p.life <= 0; }),
        list.end());
}