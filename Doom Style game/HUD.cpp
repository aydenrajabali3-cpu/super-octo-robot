#include "HUD.hpp"

HUD::HUD()
{
    font.loadFromFile("arial.ttf"); // make sure font file exists
    healthText.setFont(font);
    healthText.setCharacterSize(20);
    healthText.setFillColor(sf::Color::Red);
    healthText.setPosition(10, 10);

    ammoText.setFont(font);
    ammoText.setCharacterSize(20);
    ammoText.setFillColor(sf::Color::Yellow);
    ammoText.setPosition(10, 40);
}

void HUD::update(Player& player)
{
    healthText.setString("Health: " + std::to_string(player.health));
    ammoText.setString("Ammo: " + std::to_string(player.ammo));
}

void HUD::draw(sf::RenderWindow& window)
{
    window.draw(healthText);
    window.draw(ammoText);
}