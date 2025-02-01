/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** Krell
*/

#ifndef KRELL_HPP_
#define KRELL_HPP_

#include <iostream>

class Krell {
    public:
        virtual ~Krell() = default;
        class IModule {};
        class IDisplay {};
        virtual void draw() = 0;

    protected:
        //virtual bool _isTui() = 0; // TUI = Text User Interface || If true, use nCurses, else use SFML
};


#endif /* !KRELL_HPP_ */
