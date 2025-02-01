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

void MyNCurses::draw()
{
    clear();
    _yPos = 4;

    mvprintw(2, 2, "System Information");
    
    if (_showName) {
        mvprintw(_yPos++, 2, "Hostname: %s", hostUser.getHostname().c_str());
        mvprintw(_yPos++, 2, "Username: %s", hostUser.getUsername().c_str());
        _yPos += 2;
    }
    if (_showOS) {
        mvprintw(_yPos++, 2, "OS: %s", osKer.getOSName().c_str());
        mvprintw(_yPos++, 2, "Kernel: %s", osKer.getKernelVersion().c_str());
        _yPos += 2;
    }
    if (_showDateTime) {
        mvprintw(_yPos++, 2, "Date & Time: %s", daTime.getDateTime().c_str());
        _yPos += 2;
    }
    if (_showCPU) {
        mvprintw(_yPos++, 2, "CPU Model: %s", cpu.getCPUModel().c_str());
        mvprintw(_yPos++, 2, "CPU Cores: %s", cpu.getCPUCores().c_str());
        mvprintw(_yPos++, 2, "CPU Frequency: %s", cpu.getCPUFrequency().c_str());
        mvprintw(_yPos++, 2, "CPU Usage: %s", cpu.getCPUUsage().c_str());
        _yPos += 2;
    }
    if (_showRAM) {
        mvprintw(_yPos++, 2, "Total RAM: %s", ram.getTotalRAM().c_str());
        mvprintw(_yPos++, 2, "Used RAM: %s", ram.getUsedRAM().c_str());
        mvprintw(_yPos++, 2, "Free RAM: %s", ram.getFreeRAM().c_str());
        _yPos += 2;
    }
    refresh();
}

void MyNCurses::Init()
{
    initscr();
    noecho();
    curs_set(0);
}

ExitReason MyNCurses::subLoop()
{
    draw();
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
