#pragma once
#include <SFML/Graphics.hpp>
#include "Gameplay/Player.hpp"

class HUD
{
private:
    sf::Font font;
    sf::Text healthText;
    sf::Text ammoText;

public:
    HUD();
    void update(Player& player);
    void draw(sf::RenderWindow& window);
};