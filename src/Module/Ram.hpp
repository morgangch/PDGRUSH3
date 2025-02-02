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
    RAM();
    ~RAM() = default;
    std::string getTotalRAM();
    std::string getFreeRAM();
    std::string getUsedRAM();
    DataContainer *getDatas() override;
    void update() override;
    void calculatePercentage();
  
  private : std::string _total;
    std::string _free;
    std::string _used;
    std::string _header = "RAM\n";
};

#endif /* RAM_HPP_ */
