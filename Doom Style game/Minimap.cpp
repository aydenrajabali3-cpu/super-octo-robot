#include "Minimap.hpp"

void Minimap::draw(sf::RenderWindow& window, Map& map, Player& player)
{
    float scale = 10.0f;
    for (int x = 0; x < Map::MAP_W; x++)
    {
        for (int y = 0; y < Map::MAP_H; y++)
        {
            sf::RectangleShape tile(sf::Vector2f(scale, scale));
            tile.setPosition(x * scale, y * scale);
            tile.setFillColor(map.grid[x][y] ? sf::Color::White : sf::Color(100, 100, 100));
            window.draw(tile);
        }
    }

    sf::CircleShape p(3);
    p.setFillColor(sf::Color::Red);
    p.setPosition(player.x * scale - 3, player.y * scale - 3);
    window.draw(p);
}