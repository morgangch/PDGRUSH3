/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DisplayManager
*/

#ifndef DISPLAYMANAGER_HPP_
#define DISPLAYMANAGER_HPP_

#include "../Supervisor.hpp"
#include "../IDisplay.hpp"
#include "MyNCurses.hpp"
#include "MySFML.hpp"

enum DisplayLib {
    NCURSES, // TUI
    SFML     // GUI
};

enum ModuleType { E_HOSTUSER, E_OSKER, E_DATIME, E_CPU, E_RAM, E_POW, E_NONE };

class DisplayLibList {
  public:
    DisplayLibList(DisplayLib lib);
    ~DisplayLibList();
    IDisplay *display;
    DisplayLib displayLib;
    DisplayLibList *next;
};

class ModulesDisplayer {
  public:
    ModulesDisplayer(
        ModuleType type = E_HOSTUSER, ModulesDisplayer *prev = nullptr);
    ~ModulesDisplayer();
    void setHidden(bool isHidden) { _isHidden = isHidden; }
    void toggleHidden() { _isHidden = !_isHidden; }
    IModule *module;
    DataContainer *data;
    ModulesDisplayer *next;
    ModulesDisplayer *_prev;
    int getHighestY();
    int getHighestX();
    bool shouldDisplay()
    {
        return !_isHidden;
    }

  private:
    bool _isHidden;
};

class DisplayManager {
  public:
    DisplayManager(DisplayLib displayLib);
    ~DisplayManager();
    void loop();
    void setDisplayLib(DisplayLib displayLib);
    IDisplay *getDisplay();
    IDisplay *getDisplayWithLib(DisplayLib displayLib);
    ModulesDisplayer *modules;
    int display();
  protected:
  private:
    const DisplayLibList *_displayLibList;
    DisplayLib _displayLib;
    IDisplay *currentDisplay;
};

#endif /* !DISPLAYMANAGER_HPP_ */
