#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <map>

class SoundSystem
{
private:
    std::map<std::string, sf::SoundBuffer> buffers;
    std::map<std::string, sf::Sound> sounds;

public:
    void loadSound(const std::string& name, const std::string& file);
    void play(const std::string& name);
};