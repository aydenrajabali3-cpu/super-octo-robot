#pragma once
#include <SFML/Graphics.hpp>
#include "Rendering/Renderer.hpp"
#include "Gameplay/Player.hpp"
#include "World/Map.hpp"
#include "Gameplay/Enemy.hpp"
#include "Systems/ParticleSystem.hpp"
#include "Systems/Pathfinding.hpp"

class Engine
{
public:
    sf::RenderWindow window;
    Map map;
    Player player;
    Renderer renderer;
    std::vector<Enemy> enemies;
    ParticleSystem particles;
    Pathfinding pathfinder;

    Engine();
    void run();
};