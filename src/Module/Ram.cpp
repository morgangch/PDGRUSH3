/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** RAM
*/

#include "Ram.hpp"
#include <fstream>

std::string RAM::getTotalRAM()
{
    std::ifstream memInfo("/proc/meminfo");
    std::string line;

    while (std::getline(memInfo, line)) {
        if (line.find("MemTotal") != std::string::npos)
            return line.substr(line.find(":") + 2);
    }
    return "Unknown";
}

std::string RAM::getFreeRAM()
{
    std::ifstream memInfo("/proc/meminfo");
    std::string line;

    while (std::getline(memInfo, line)) {
        if (line.find("MemFree") != std::string::npos)
            return line.substr(line.find(":") + 2);
    }
    return "Unknown";
}

std::string RAM::getUsedRAM()
{
    std::ifstream memInfo("/proc/meminfo");
    std::string line;
    long total = 0, free = 0;

    while (std::getline(memInfo, line)) {
        if (line.find("MemTotal") != std::string::npos) {
            total = std::stol(line.substr(line.find(":") + 2));
        } else if (line.find("MemFree") != std::string::npos) {
            free = std::stol(line.substr(line.find(":") + 2));
        }
    }
    long used = total - free;
    return std::to_string(used) + " kB";
}
