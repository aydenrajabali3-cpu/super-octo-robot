#include "Door.hpp"

Door::Door(double px, double py)
{
    x = px; y = py;
    open = false;
    progress = 0;
    speed = 1.0;
}

void Door::update(double dt)
{
    if (open && progress < 1.0) progress += speed * dt;
    if (!open && progress > 0.0) progress -= speed * dt;

    if (progress > 1.0) progress = 1.0;
    if (progress < 0.0) progress = 0.0;
}

void Door::toggle()
{
    open = !open;
}