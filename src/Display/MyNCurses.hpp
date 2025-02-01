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
};

#endif /* !MYNCURSES_HPP_ */
