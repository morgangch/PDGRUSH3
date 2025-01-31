/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DisplayManager
*/

#include "DisplayManager.hpp"
#include <stdio.h>

DisplayManager::DisplayManager(bool tui)
{
    _tui = tui;
    if (_tui) {
        printf("TUI mode\n");
    } else {
        printf("SFML mode\n");
    }
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
    return 0;
}
