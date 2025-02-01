/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** CPU
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include <string>

class CPU {
public:
    static std::string getCPUModel();
    static std::string getCPUCores();
    static std::string getCPUFrequency();
    static std::string getCPUUsage();
};

#endif /* CPU_HPP_ */
