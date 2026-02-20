#include "Renderer.hpp"
#include <cmath>

Renderer::Renderer(sf::RenderWindow& win)
    : window(win)
{
    width = window.getSize().x;
    height = window.getSize().y;
    zBuffer.resize(width);
}

void Renderer::render(Map& map, Player& player, std::vector<Enemy>& enemies, ParticleSystem& particles)
{
    window.clear(sf::Color(50, 50, 50)); // sky/fog

    // ======== RAYCAST WALLS ========
    for (int x = 0; x < width; x++)
    {
        double cameraX = 2 * x / double(width) - 1;
        double rayDirX = player.dirX + player.planeX * cameraX;
        double rayDirY = player.dirY + player.planeY * cameraX;

        int mapX = int(player.x);
        int mapY = int(player.y);

        double sideDistX, sideDistY;
        double deltaDistX = std::abs(1 / rayDirX);
        double deltaDistY = std::abs(1 / rayDirY);
        double perpWallDist;

        int stepX, stepY;
        int hit = 0, side;

        if (rayDirX < 0) { stepX = -1; sideDistX = (player.x - mapX) * deltaDistX; }
        else { stepX = 1; sideDistX = (mapX + 1.0 - player.x) * deltaDistX; }
        if (rayDirY < 0) { stepY = -1; sideDistY = (player.y - mapY) * deltaDistY; }
        else { stepY = 1; sideDistY = (mapY + 1.0 - player.y) * deltaDistY; }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX; mapX += stepX; side = 0;
            }
            else
            {
                sideDistY += deltaDistY; mapY += stepY; side = 1;
            }

            if (map.isWall(mapX, mapY)) hit = 1;
        }

        if (side == 0) perpWallDist = (mapX - player.x + (1 - stepX) / 2) / rayDirX;
        else perpWallDist = (mapY - player.y + (1 - stepY) / 2) / rayDirY;

        zBuffer[x] = perpWallDist;

        int lineHeight = int(height / perpWallDist);
        int drawStart = -lineHeight / 2 + height / 2;
        int drawEnd = lineHeight / 2 + height / 2;

        sf::RectangleShape wall(sf::Vector2f(1, lineHeight));
        wall.setPosition(x, drawStart);

        float shade = 1.f / (1.f + perpWallDist * 0.1f);
        if (side == 1) shade *= 0.7f; // darken side walls
        wall.setFillColor(sf::Color(200 * shade, 0, 0));
        window.draw(wall);
    }

    // ======== ENEMIES ========
    for (auto& e : enemies)
    {
        if (e.health <= 0) continue;

        double spriteX = e.x - player.x;
        double spriteY = e.y - player.y;

        double invDet = 1.0 / (player.planeX * player.dirY - player.dirX * player.planeY);
        double transformX = invDet * (player.dirY * spriteX - player.dirX * spriteY);
        double transformY = invDet * (-player.planeY * spriteX + player.planeX * spriteY);

        int spriteScreenX = int((width / 2) * (1 + transformX / transformY));
        int spriteHeight = abs(int(height / transformY));
        int drawStartY = -spriteHeight / 2 + height / 2;

        sf::RectangleShape enemyShape(sf::Vector2f(spriteHeight, spriteHeight));
        enemyShape.setPosition(spriteScreenX - spriteHeight / 2, drawStartY);
        enemyShape.setFillColor(sf::Color::Green);

        window.draw(enemyShape);
    }

    // ======== PARTICLES ========
    for (auto& p : particles.list)
    {
        sf::CircleShape particle(2);
        particle.setPosition(p.x * 10, p.y * 10);
        particle.setFillColor(sf::Color::Yellow);
        window.draw(particle);
    }
}