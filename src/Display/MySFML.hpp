/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** NCurses
*/

#ifndef MYSFML_HPP_
#define MYSFML_HPP_

#include "DisplayManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Module/HostUser.hpp"
#include "../Module/OSKer.hpp"
#include "../Module/DaTime.hpp"

class MySFML : virtual public IDisplay {
    public:
        MySFML();
        ~MySFML() = default;
        virtual void draw(DataContainer *data) override;
        void Init() override;
        ExitReason subLoop(ModulesDisplayer *modules) override;
        void displayModules(ModulesDisplayer *modules);

    protected:
    private:
        void createText(sf::Text *text);
        sf::RenderWindow *_window;
        sf::Font _font;
        void onResize();
};

#endif /* !MYSFML_HPP_ */
