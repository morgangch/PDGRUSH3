/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** Supervisor
*/

#include "Supervisor.hpp"
#include "Display/DisplayManager.hpp"

int supervisor(bool tui)
{
    DisplayManager displayManager(tui ? NCURSES : SFML);
    displayManager.getDisplay()->Init();
    displayManager.loop();
    return 0;
}
