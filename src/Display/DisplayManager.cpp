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
    currentDisplay = getDisplayWithLib(displayLib);
    modules = new ModulesDisplayer(E_HOSTUSER, nullptr);
}

DisplayManager::~DisplayManager()
{
    delete _displayLibList;
    delete currentDisplay;
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
        next = nullptr;
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
        if (tmp->next == nullptr)
            return nullptr;
        else
            tmp = tmp->next;
    return tmp->display;
}

void DisplayManager::setDisplayLib(DisplayLib displayLib)
{
    currentDisplay = getDisplayWithLib(displayLib);
    _displayLib = displayLib;
}

void DisplayManager::loop()
{
    ExitReason exitReason = NONE;
    while (exitReason == NONE) {
        for (ModulesDisplayer *tmp = modules; tmp; tmp = tmp->next) {
            if (tmp->shouldDisplay())
                tmp->module->update();
        }
        exitReason = currentDisplay->subLoop(modules);
    }
    if (exitReason == EXIT) {
        exit(0);
    } else if (exitReason == CHANGE_LIB) {
        if (_displayLib == NCURSES)
            setDisplayLib(SFML);
        else
            setDisplayLib(NCURSES);
        this->currentDisplay->Init();
        return loop();
    }
}

int ModulesDisplayer::getHighestY()
{
    int highestY = 0;
    ModulesDisplayer *tmp = this;

    while (tmp) {
        if (tmp->data->y > highestY)
            highestY = tmp->data->y;
        tmp = tmp->next;
    }
    return highestY;
}

ModulesDisplayer::~ModulesDisplayer()
{
    delete module;
    if (next)
        delete next;
}

ModulesDisplayer::ModulesDisplayer(ModuleType type, ModulesDisplayer *prev)
{
    switch (type) {
        case E_HOSTUSER:
            module = new HostUser;
            next = new ModulesDisplayer(E_OSKER, this);
            break;
        case E_OSKER:
            module = new OSKer;
            next = new ModulesDisplayer(E_DATIME, this);
            break;
        case E_DATIME:
            module = new DaTime;
            next = new ModulesDisplayer(E_CPU, this);
            break;
        case E_CPU:
            module = new CPU;
            next = new ModulesDisplayer(E_RAM, this);
            break;
        case E_RAM:
            module = new RAM;
            next = nullptr;
            break;
        default:
            module = nullptr;
            next = nullptr;
            break;
    }
    data = module->getDatas();
    data->y = getHighestY() + 1;
    _prev = prev;
    _isHidden = false;
}