/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** RAM
*/

#include "Ram.hpp"
#include <fstream>

RAM::RAM()
{
    update();
}

std::string RAM::getTotalRAM()
{
    std::ifstream memInfo("/proc/meminfo");
    std::string line, label, value;

    while (std::getline(memInfo, line)) {
        std::istringstream iss(line);
        iss >> label >> value; // Ignore le label "MemTotal:" et récupère uniquement la valeur
        if (label == "MemTotal:")
            return value + " kB Total";
    }
    return "Unknown";
}

std::string RAM::getFreeRAM()
{
    std::ifstream memInfo("/proc/meminfo");
    std::string line, label, value;

    while (std::getline(memInfo, line)) {
        std::istringstream iss(line);
        iss >> label >> value; // Ignore le label "MemTotal:" et récupère uniquement la valeur
        if (label == "MemFree:")
            return value;
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
    return std::to_string(used);
}

DataContainer *RAM::getDatas()
{
    DataContainer *data = new DataContainer(0, 0, _header, 4);
    data->next = new DataContainer(0, 0, _total);
    data->next->next = new DataContainer(0, 0, _used);
    data->next->next->next = new DataContainer(0, 0, _free);
    return data;
}

void RAM::update()
{
    _total = getTotalRAM();
    _free = getFreeRAM();
    _used = getUsedRAM();
    calculatePercentage();
}

void RAM::calculatePercentage()
{
    long total = std::stol(_total);
    long used = std::stol(_used);
    long free = std::stol(_free);

    std::string usedPercentage = std::to_string((used * 100) / total);
    std::string freePercentage = std::to_string((free * 100) / total);
    _used += " kB Used (" + usedPercentage + "%)";
    _free += " kB Free (" + freePercentage + "%)";
}
