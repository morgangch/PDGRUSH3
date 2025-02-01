/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** NCurses
*/

#include "MySFML.hpp"

MySFML::MySFML()
{
}

void MySFML::draw()
{
    sf::Text text;
    text.setString("Hostname: " + hostUser.getHostname());
    text.setFillColor(sf::Color::Red);
    text.setPosition(100, 100);
    _window->draw(text);
}

void MySFML::Init()
{
    _window =
        new sf::RenderWindow(sf::VideoMode(800, 600), "System Information");
    _window->setFramerateLimit(60);
}

ExitReason MySFML::subLoop()
{
    if (_window->isOpen()) {
        _window->clear();
        draw();
        _window->display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            _window->close();
            return EXIT;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            _window->close();
            return CHANGE_LIB;
        }
        if (sf::Event event; _window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window->close();
                return EXIT;
            }
        }
    }
    return NONE;
}