#pragma once
#include "Gameplay/Player.hpp"
#include "World/Map.hpp"
#include <string>

class SaveSystem
{
public:
    static void save(const Player& player, Map& map, const std::string& filename);
    static void load(Player& player, Map& map, const std::string& filename);
};