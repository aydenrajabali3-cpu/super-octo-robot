#include "Player.hpp"
#include <SFML/Window.hpp>
#include <cmath>

Player::Player(double startX, double startY)
{
    x = startX;
    y = startY;
    dirX = -1;
    dirY = 0;
    planeX = 0;
    planeY = 0.66; // FOV 66 degrees
}

void Player::update(double dt, Map& map)
{
    double moveSpeed = dt * 5.0;   // movement speed
    double rotSpeed = dt * 3.0;    // rotation speed

    // Movement: W/S
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        if (!map.isWall(int(x + dirX * moveSpeed), int(y)))
            x += dirX * moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        if (!map.isWall(int(x - dirX * moveSpeed), int(y)))
            x -= dirX * moveSpeed;

    // Rotation: A/D
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        double oldDirX = dirX;
        dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
        dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
        planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        double oldDirX = dirX;
        dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
        dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
        planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
}

void Player::shoot()
{
    if (ammo <= 0) return;
    ammo--;
    // Shooting logic will interact with enemies in Engine.cpp
}