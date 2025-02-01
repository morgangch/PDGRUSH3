/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** NCurses
*/

#ifndef MYSFML_HPP_
#define MYSFML_HPP_

#include "DisplayManager.hpp"

class MySFML : virtual public IDisplay {
    public:
        MySFML();
        ~MySFML() = default;
        void draw();

    protected:
    private:
};

#endif /* !MYSFML_HPP_ */
