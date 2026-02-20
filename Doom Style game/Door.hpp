#pragma once
#include <SFML/Graphics.hpp>

class Door
{
public:
    double x, y;
    bool open;
    double progress; // 0 closed -> 1 fully open
    double speed;

    Door(double px, double py);

    void update(double dt);
    void toggle();
};