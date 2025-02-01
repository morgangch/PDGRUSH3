/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** NCurses
*/

#include "MyNCurses.hpp"

MyNCurses::MyNCurses()
{
    initscr();
    noecho();
    curs_set(0);
}

MyNCurses::~MyNCurses()
{
    endwin();
}

void MyNCurses::draw()
{
    clear();

    mvprintw(2, 2, "System Information");
    mvprintw(4, 2, "Hostname: %s", hostUser.getHostname().c_str());
    mvprintw(5, 2, "Username: %s", hostUser.getUsername().c_str());
    mvprintw(7, 2, "OS: %s", osKer.getOSName().c_str());
    mvprintw(8, 2, "Kernel: %s", osKer.getKernelVersion().c_str());
    mvprintw(10, 2, "Date & Time: %s", daTime.getDateTime().c_str());

    refresh();

    int ch = getch();
    if (ch == 'q')
        return;
}
