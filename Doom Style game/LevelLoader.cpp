#include "LevelLoader.hpp"

void LevelLoader::load(Map& map, const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    int y = 0;
    while (std::getline(file, line) && y < Map::MAP_H)
    {
        std::istringstream ss(line);
        for (int x = 0; x < Map::MAP_W; x++)
        {
            int val;
            if (!(ss >> val)) break;
            map.grid[x][y] = val;
        }
        y++;
    }
}