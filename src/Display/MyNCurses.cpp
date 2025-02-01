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
}

MyNCurses::~MyNCurses()
{
    endwin();
}

void displayModules(ModulesDisplayer *modules)
{
    MyNCurses ncursesInstance;
    for (ModulesDisplayer *tmp = modules; tmp; tmp = tmp->next) {
        std::cout << tmp->data->value << std::endl;
        if (tmp->shouldDisplay())
            ncursesInstance.draw(tmp->data);
    }
}

void MyNCurses::draw(DataContainer *data)
{
    mvprintw(data->y, data->x, "%s\n", (data->value).c_str());
}

void MyNCurses::Init()
{
    initscr();
    noecho();
    curs_set(0);
    timeout(500);
}

ExitReason MyNCurses::subLoop(ModulesDisplayer *modules)
{
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
