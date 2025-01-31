/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DisplayManager
*/

#include "DisplayManager.hpp"

DisplayManager::DisplayManager(bool tui)
{
    _tui = tui;
}

DisplayManager::~DisplayManager()
{
}

int DisplayManager::display()
{
    NCurses ncurses;

    if (_tui) {
        ncurses.display();
    } else {
        // display with sfml
    }
}
