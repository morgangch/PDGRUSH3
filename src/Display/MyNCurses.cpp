/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** NCurses
*/

#include "MyNCurses.hpp"
#include <unistd.h>

MyNCurses::MyNCurses()
{
    initscr();
    noecho();
    curs_set(0);
    timeout(500);
}

MyNCurses::~MyNCurses()
{
    endwin();
}

void displayModules(ModulesDisplayer *modules)
{
    MyNCurses ncursesInstance;
    for (ModulesDisplayer *tmp = modules; tmp; tmp = tmp->next) {
        if (tmp->shouldDisplay())
            ncursesInstance.draw(tmp->data);
    }
}

void MyNCurses::draw(DataContainer *data)
{
    if (data)
        mvprintw(data->x, data->y, "%s\n", (data->value).c_str());
}

void MyNCurses::Init()
{
    initscr();
    noecho();
    curs_set(0);
}

ExitReason MyNCurses::subLoop(ModulesDisplayer *modules)
{
    MyNCurses ncursesInstance;
    displayModules(modules);
    refresh();

    int ch = getch();
    if (ch == 'q') {
        endwin();
        return EXIT;
    }
    if (ch == 'c') {
        endwin();
        return CHANGE_LIB;
    }
    return NONE;
}
