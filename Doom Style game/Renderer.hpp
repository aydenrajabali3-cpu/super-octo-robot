#pragma once
#include <SFML/Graphics.hpp>
#include "World/Map.hpp"
#include "Gameplay/Player.hpp"
#include "Gameplay/Enemy.hpp"
#include "Systems/ParticleSystem.hpp"
#include <vector>

class Renderer
{
private:
    sf::RenderWindow& window;
    int width, height;
    std::vector<double> zBuffer;

public:
    Renderer(sf::RenderWindow& win);
    void render(Map& map, Player& player, std::vector<Enemy>& enemies, ParticleSystem& particles);
};