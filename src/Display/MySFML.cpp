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
    sf::RenderWindow window(sf::VideoMode(800, 600), "System Information");
    sf::Text text("Hostname: " + hostUser.getHostname(), sf::Font(), 50);
    text.setFillColor(sf::Color::Red);
    text.setPosition(100, 100);

    while (window.isOpen()) {
        window.clear();
        window.draw(text);
        window.display();
    }
}

void MySFML::Init()
{
    sf::Window window(sf::VideoMode({800, 600}), "System Information");
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(100, 250, 50));
}