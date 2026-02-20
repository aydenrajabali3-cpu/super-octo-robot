#pragma once
#include "Gameplay/Player.hpp"
#include "World/Map.hpp"
#include "Systems/Pathfinding.hpp"
#include <cmath>

enum class EnemyState { Idle, Patrol, Chase, Attack, Dead };

class Enemy
{
public:
    double x, y;
    int health;
    EnemyState state;

    Enemy(double startX = 8, double startY = 8);

    void update(double dt, Player& player, Map& map, Pathfinding& pathfinder);
};