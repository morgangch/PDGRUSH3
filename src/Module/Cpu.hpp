/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** CPU
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include <string>
#include "IModule.hpp"

class CPU : public IModule {
  public:
    CPU();
    ~CPU() = default;
    std::string getCPUModel();
    std::string getCPUCores();
    std::string getCPUFrequency();
    std::string getCPUUsage();
    DataContainer *getDatas() override;
    void update() override;
  private:
    std::string _model;
    std::string _cores;
    std::string _frequency;
    std::string _usage;
    std::string _format;
};

#endif /* CPU_HPP_ */
