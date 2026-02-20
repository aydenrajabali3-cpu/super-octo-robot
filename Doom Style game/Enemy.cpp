#include "Enemy.hpp"

Enemy::Enemy(double startX, double startY)
{
    x = startX;
    y = startY;
    health = 100;
    state = EnemyState::Idle;
}

void Enemy::update(double dt, Player& player, Map& map, Pathfinding& pathfinder)
{
    if (health <= 0) { state = EnemyState::Dead; return; }

    double dx = player.x - x;
    double dy = player.y - y;
    double dist = std::sqrt(dx * dx + dy * dy);

    if (dist < 0.5) state = EnemyState::Attack;
    else if (dist < 6.0) state = EnemyState::Chase;
    else state = EnemyState::Idle;

    switch (state)
    {
    case EnemyState::Idle:
        break;

    case EnemyState::Chase:
        // Simple move toward player
        x += (dx / dist) * dt * 2.0;
        y += (dy / dist) * dt * 2.0;
        break;

    case EnemyState::Attack:
        // Could reduce player health here
        break;

    case EnemyState::Dead:
        break;

    default: break;
    }
}