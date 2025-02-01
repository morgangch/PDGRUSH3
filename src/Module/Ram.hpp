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
    RAM() : _total(getTotalRAM()), _free(getFreeRAM()), _used(getUsedRAM()) {};
    std::string getTotalRAM();
    std::string getFreeRAM();
    std::string getUsedRAM();
    DataContainer *getDatas() override;
  private:
    std::string _total;
    std::string _free;
    std::string _used;
};

#endif /* RAM_HPP_ */
