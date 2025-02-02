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
    if (!data)
        return;
    sf::Text text;
    createText(&text);
    text.setString(data->value);
    text.setPosition(data->x * 0, data->y * 30);
    _window->draw(text);
    if (data->next) {
        data->next->y = data->y + 1;
        draw(data->next);
    }
}

void MySFML::Init()
{
    _window =
        new sf::RenderWindow(sf::VideoMode(800, 800), "MyGKrellm");
    _window->setFramerateLimit(4);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window->close();
        return EXIT;
    }
    return NONE;
}

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
            if (event.type == sf::Event::Resized)
                onResize();
        }
    }
    return NONE;
}

void MySFML::onResize()
{
    sf::Vector2u size = _window->getSize();
    sf::View view = _window->getView();
    view.setSize(size.x, size.y);
    view.setCenter(size.x / 2, size.y / 2);
    _window->setView(view);
}

void MySFML::displayModules(ModulesDisplayer *modules)
{
    for (ModulesDisplayer *tmp = modules; tmp; tmp = tmp->next) {
        if (tmp->shouldDisplay())
            this->draw(tmp->data);
    }
}
