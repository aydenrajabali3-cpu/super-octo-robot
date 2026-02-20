#pragma once
#include "World/Map.hpp"
#include <SFML/Graphics.hpp>

class Player
{
public:
    double x, y;         // Position
    double dirX, dirY;   // Direction vector
    double planeX, planeY; // Camera plane
    int health = 100;
    int ammo = 50;

    Player(double startX = 12, double startY = 12);

    void update(double dt, Map& map);
    void shoot();
};