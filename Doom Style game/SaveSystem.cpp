#include "SaveSystem.hpp"
#include <fstream>

void SaveSystem::save(const Player& player, Map& map, const std::string& filename)
{
    std::ofstream file(filename, std::ios::binary);
    file.write((char*)&player.x, sizeof(player.x));
    file.write((char*)&player.y, sizeof(player.y));
    file.write((char*)&player.health, sizeof(player.health));
    file.write((char*)&player.ammo, sizeof(player.ammo));
    file.write((char*)map.grid, sizeof(map.grid));
}

void SaveSystem::load(Player& player, Map& map, const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) return;
    file.read((char*)&player.x, sizeof(player.x));
    file.read((char*)&player.y, sizeof(player.y));
    file.read((char*)&player.health, sizeof(player.health));
    file.read((char*)&player.ammo, sizeof(player.ammo));
    file.read((char*)map.grid, sizeof(map.grid));
}