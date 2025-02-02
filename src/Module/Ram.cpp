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
    std::string line, label, value;

    while (std::getline(memInfo, line)) {
        std::istringstream iss(line);
        iss >> label >> value; // Ignore le label "MemTotal:" et récupère uniquement la valeur
        if (label == "MemTotal:")
            return value + " kB"; // Ajoute "kB" pour garder l'unité
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
            return value + " kB"; // Ajoute "kB" pour garder l'unité
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

DataContainer *RAM::getDatas()
{
    DataContainer *data(new DataContainer(0, 0, _total, 3));
    data->next = new DataContainer(0, 0, _free);
    data->next->next = new DataContainer(0, 0, _used);
    return data;
}