#include "Pathfinding.hpp"
#include <algorithm>
#include <cmath>

std::vector<std::pair<int, int>> Pathfinding::findPath(Map& map, int startX, int startY, int endX, int endY)
{
    const int dx[4] = { 1, -1, 0, 0 };
    const int dy[4] = { 0, 0, 1, -1 };

    std::vector<std::vector<bool>> visited(Map::MAP_W, std::vector<bool>(Map::MAP_H, false));
    std::vector<std::vector<std::pair<int, int>>> parent(Map::MAP_W, std::vector<std::pair<int, int>>(Map::MAP_H, { -1,-1 }));

    std::queue<std::pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front(); q.pop();
        if (x == endX && y == endY) break;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= Map::MAP_W || ny >= Map::MAP_H) continue;
            if (visited[nx][ny] || map.isWall(nx, ny)) continue;

            visited[nx][ny] = true;
            parent[nx][ny] = { x,y };
            q.push({ nx, ny });
        }
    }

    std::vector<std::pair<int, int>> path;
    int cx = endX, cy = endY;
    while (cx != -1 && cy != -1)
    {
        path.push_back({ cx, cy });
        auto [px, py] = parent[cx][cy];
        cx = px; cy = py;
    }
    std::reverse(path.begin(), path.end());
    return path;
}