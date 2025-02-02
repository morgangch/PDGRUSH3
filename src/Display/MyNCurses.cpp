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

void MyNCurses::displayModules(ModulesDisplayer *modules)
{
    for (ModulesDisplayer *tmp = modules; tmp; tmp = tmp->next) {
        if (tmp->shouldDisplay())
            draw(tmp->data);
    }
}

void MyNCurses::draw(DataContainer *data)
{
    if (!data)
        return;
    if (!data->next) {
        mvprintw(data->y, 0, "%s", (data->value).c_str());
        return;
    }
    mvprintw(data->y, 0, "%s", (data->value).c_str());
    draw(data->next);
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
