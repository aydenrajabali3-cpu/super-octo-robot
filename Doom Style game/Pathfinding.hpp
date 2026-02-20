#pragma once
#include <vector>
#include <queue>
#include <utility>
#include "World/Map.hpp"

struct Node
{
    int x, y;
    double cost;
};

class Pathfinding
{
public:
    std::vector<std::pair<int, int>> findPath(Map& map, int startX, int startY, int endX, int endY);
};