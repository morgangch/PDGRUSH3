/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** NCurses
*/

#ifndef MYNCURSES_HPP_
#define MYNCURSES_HPP_

#include "DisplayManager.hpp"

class MyNCurses : virtual public IDisplay {
    public:
        MyNCurses();
        ~MyNCurses() = default;
        void draw() override;

    protected:
    private:
};

#endif /* !MYNCURSES_HPP_ */
