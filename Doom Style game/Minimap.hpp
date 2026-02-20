#pragma once
#include <SFML/Graphics.hpp>
#include "World/Map.hpp"
#include "Gameplay/Player.hpp"

class Minimap
{
public:
    void draw(sf::RenderWindow& window, Map& map, Player& player);
};