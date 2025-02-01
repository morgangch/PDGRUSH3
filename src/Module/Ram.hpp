/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** RAM
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include <string>

class RAM {
public:
    static std::string getTotalRAM();
    static std::string getFreeRAM();
    static std::string getUsedRAM();
};

#endif /* RAM_HPP_ */
