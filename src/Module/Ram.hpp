/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** RAM
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include <string>
#include "IModule.hpp"

class RAM : public IModule {
  public:
    std::string getTotalRAM();
    std::string getFreeRAM();
    std::string getUsedRAM();
    void draw(std::function<void(DataContainer *)> func) override;
};

#endif /* RAM_HPP_ */
