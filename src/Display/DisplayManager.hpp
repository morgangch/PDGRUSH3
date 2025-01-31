/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DisplayManager
*/

#ifndef DISPLAYMANAGER_HPP_
#define DISPLAYMANAGER_HPP_

#include "../IDisplay.hpp"
#include "NCurses.hpp"

class DisplayManager {
    public:
        DisplayManager(bool tui);
        ~DisplayManager();

        bool isTui() { return _tui; }

        int display();

    protected:
    private:
        bool _tui;
};

#endif /* !DISPLAYMANAGER_HPP_ */
