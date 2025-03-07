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
    mvprintw(data->y, data->x, "%s", (data->value).c_str());
    if (data->next) {
        data->next->y = data->y + 1;
        draw(data->next);
    }
}

void MyNCurses::Init()
{
    initscr();
    noecho();
    curs_set(0);
    timeout(500);
    halfdelay(2);
}

void listenKeys(ModulesDisplayer *modules, int ch)
{
    if (ch == 'a') {
        modules->hideModule(E_HOSTUSER, modules->shouldDisplay());
    }
    if (ch == 'z') {
        modules->hideModule(E_OSKER, modules->shouldDisplay());
    }
    if (ch == 'e') {
        modules->hideModule(E_DATIME, modules->shouldDisplay());
    }
    if (ch == 'r') {
        modules->hideModule(E_CPU, modules->shouldDisplay());
    }
    if (ch == 't') {
        modules->hideModule(E_RAM, modules->shouldDisplay());
    }
    if (ch == 'y') {
        modules->hideModule(E_POW, modules->shouldDisplay());
    }
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
    listenKeys(modules, ch);
    return NONE;
}
