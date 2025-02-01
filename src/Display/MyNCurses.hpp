/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** NCurses
*/

#ifndef MYNCURSES_HPP_
#define MYNCURSES_HPP_

#include "DisplayManager.hpp"
#include <ncurses.h>
#include "../Module/HostUser.hpp"
#include "../Module/OSKer.hpp"
#include "../Module/DaTime.hpp"

class MyNCurses : public IDisplay {
    public:
        MyNCurses();
        ~MyNCurses();
        void draw() override;
        void Init() override;
        ExitReason subLoop() override;
    private:
    bool _isRunning;
    bool _showName = true;
    bool _showOS = true;
    bool _showDateTime = true;

    bool _showCPU = true;

    bool _showRAM = true;

    int _yPos = 4;
};

#endif /* !MYNCURSES_HPP_ */
