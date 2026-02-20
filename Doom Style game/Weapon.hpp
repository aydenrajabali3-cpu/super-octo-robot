#pragma once

class Weapon
{
public:
    int damage;
    float fireRate; // shots per second
    float cooldown;

    Weapon(int dmg = 50, float rate = 2.0f);

    bool canFire(float dt);
};