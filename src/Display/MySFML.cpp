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

void MySFML::draw(DataContainer *data)
{
    if (data) {
        sf::Text text;
        createText(&text);
        text.setString(data->value);
        text.setPosition(data->x, data->y);
        _window->draw(text);
    }
}

void MySFML::Init()
{
    _window =
        new sf::RenderWindow(sf::VideoMode(800, 600), "System Information");
    _window->setFramerateLimit(60);
    this->_font.loadFromFile("font.ttf");
    if (!this->_font.loadFromFile("font.ttf")) {
        exit(0xdeadbeef);
    }
}

void MySFML::createText(sf::Text *text)
{
    text->setFont(this->_font);
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::White);
}

ExitReason keyPress(sf::RenderWindow *window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        window->close();
        return EXIT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        window->close();
        return CHANGE_LIB;
    }
    return NONE;
}

// void MySFML::displaymodules(ModulesDisplayer *modules)
// {
//     MySFML sfmlInstance;
//     for (ModulesDisplayer *tmp = modules; tmp; tmp = tmp->next) {
//         if (tmp->shouldDisplay())
//             sfmlInstance.draw(tmp->data);
//     }
// }

ExitReason MySFML::subLoop(ModulesDisplayer *modules)
{
    if (_window->isOpen()) {
        _window->clear();
        MySFML sfmlInstance;
        this->displayModules(modules);
        _window->display();

        sf::Event event;
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window->close();
                return EXIT;
            }
            if (event.type == sf::Event::KeyPressed
                && keyPress(_window) != NONE) {
                return keyPress(_window);
            }
        }
    }
    return NONE;
}

void MySFML::displayModules(ModulesDisplayer *modules)
{
    for (ModulesDisplayer *tmp = modules; tmp; tmp = tmp->next) {
        if (tmp->shouldDisplay())
            this->draw(tmp->data);
    }
}
