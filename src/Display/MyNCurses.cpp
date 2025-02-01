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
    _isRunning = true;
}

MyNCurses::~MyNCurses()
{
    endwin();
}

void displayModules()
{
    HostUser hostUser;
    OSKer osKer;
    DaTime daTime;
    CPU cpu;
    RAM ram;
    MySFML sfmlInstance;
    hostUser.draw([&sfmlInstance](DataContainer *data) {
        sfmlInstance.draw(data);
    });
    osKer.draw([&sfmlInstance](DataContainer *data) {
        sfmlInstance.draw(data);
    });
    daTime.draw([&sfmlInstance](DataContainer *data) {
        sfmlInstance.draw(data);
    });
    cpu.draw([&sfmlInstance](DataContainer *data) {
        sfmlInstance.draw(data);
    });
    ram.draw([&sfmlInstance](DataContainer *data) {
        sfmlInstance.draw(data);
    });
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

ExitReason MyNCurses::subLoop()
{
    MyNCurses ncursesInstance;
    daTime.draw([&ncursesInstance](DataContainer *data) {
        ncursesInstance.draw(data);
    });
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
    if (ch == '1')
        _showName = !_showName;
    else if (ch == '2')
        _showOS = !_showOS;
    else if (ch == '3')
        _showDateTime = !_showDateTime;
    else if (ch == '4')
        _showCPU = !_showCPU;
    else if (ch == '5')
        _showRAM = !_showRAM;
    return NONE;
}
