#include "Engine.hpp"

Engine::Engine()
    : window(sf::VideoMode(1280, 720), "Retro FPS Engine"),
    renderer(window)
{
    window.setFramerateLimit(60);

    enemies.emplace_back(5, 5);
    enemies.emplace_back(10, 10);
}

void Engine::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        player.update(dt, map);
        for (auto& e : enemies)
            e.update(dt, player, map, pathfinder);

        particles.update(dt);

        renderer.render(map, player, enemies, particles);

        window.display();
    }
}