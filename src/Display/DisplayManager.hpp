/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DisplayManager
*/

#ifndef DISPLAYMANAGER_HPP_
#define DISPLAYMANAGER_HPP_

#include "../IDisplay.hpp"
#include "MyNCurses.hpp"
#include "MySFML.hpp"

enum DisplayLib {
    NCURSES, // TUI
    SFML     // GUI
};

class DisplayLibList {
  public:
    DisplayLibList(DisplayLib lib);
    ~DisplayLibList();
    IDisplay *display;
    DisplayLib displayLib;
    DisplayLibList *next;
};

class DisplayManager {
  public:
    DisplayManager(DisplayLib displayLib);
    ~DisplayManager();
    void loop();
    void setDisplayLib(DisplayLib displayLib);
    IDisplay *getDisplay();
    IDisplay *getDisplayWithLib(DisplayLib displayLib);
    int display();

  protected:
  private:
    const DisplayLibList *_displayLibList;
    DisplayLib _displayLib;
    IDisplay *currentDisplay;
};

#endif /* !DISPLAYMANAGER_HPP_ */
