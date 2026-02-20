#include "Weapon.hpp"

Weapon::Weapon(int dmg, float rate)
{
    damage = dmg;
    fireRate = rate;
    cooldown = 0.0f;
}

bool Weapon::canFire(float dt)
{
    cooldown -= dt;
    if (cooldown <= 0)
    {
        cooldown = 1.0f / fireRate;
        return true;
    }
    return false;
}