#pragma once
#include "Map.hpp"
#include <string>
#include <fstream>
#include <sstream>

class LevelLoader
{
public:
    static void load(Map& map, const std::string& filename);
};