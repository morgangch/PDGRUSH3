/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DisplayManager
*/

#include "DisplayManager.hpp"
#include <stdio.h>

DisplayManager::DisplayManager(DisplayLib displayLib)
{
    _displayLib = displayLib;
    _displayLibList = new DisplayLibList(NCURSES);
    currentDisplay = _displayLibList->display;
}

DisplayManager::~DisplayManager()
{
}

int DisplayManager::display()
{
    return 0;
}

DisplayLibList::DisplayLibList(DisplayLib lib)
{
    if (lib == NCURSES) {
        display = (IDisplay *) new MyNCurses;
        displayLib = NCURSES;
        next = new DisplayLibList(SFML);
    } else if (lib == SFML) {
        display = (IDisplay *) new MySFML;
        displayLib = SFML;
        next = nullptr; // Fin de la liste
    }
}

DisplayLibList::~DisplayLibList()
{
    delete display;
    delete next;
}

IDisplay *DisplayManager::getDisplay()
{
    return currentDisplay;
}

IDisplay *DisplayManager::getDisplayWithLib(DisplayLib displayLib)
{
    const DisplayLibList *tmp = _displayLibList;

    while (tmp->displayLib != displayLib)
        tmp = tmp->next;
    return tmp->display;
}

void DisplayManager::setDisplayLib(DisplayLib displayLib)
{
    currentDisplay = getDisplayWithLib(displayLib);
    displayLib = displayLib;
}

void DisplayManager::loop()
{
    while (true) {
        currentDisplay->draw();
    }
}
