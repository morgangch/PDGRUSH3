/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** CPU
*/

#include "Cpu.hpp"
#include <fstream>
#include <sstream>

std::string CPU::getCPUModel()
{
    std::ifstream cpuInfo("/proc/cpuinfo");
    std::string line;

    while (std::getline(cpuInfo, line)) {
        if (line.find("model name") != std::string::npos)
            return line.substr(line.find(":") + 2);
    }
    return "Unknown CPU Model";
}

std::string CPU::getCPUCores()
{
    std::ifstream cpuInfo("/proc/cpuinfo");
    std::string line;
    int cores = 0;

    while (std::getline(cpuInfo, line)) {
        if (line.find("processor") != std::string::npos)
            cores++;
    }
    return std::to_string(cores);
}

std::string CPU::getCPUFrequency()
{
    std::ifstream cpuInfo("/proc/cpuinfo");
    std::string line;

    while (std::getline(cpuInfo, line)) {
        if (line.find("cpu MHz") != std::string::npos)
            return line.substr(line.find(":") + 2) + " MHz";
    }
    return "Unknown Frequency";
}

std::string CPU::getCPUUsage()
{
    std::ifstream file("/proc/stat");
    std::string line;

    if (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string cpu;
        long user, nice, system, idle;
        iss >> cpu >> user >> nice >> system >> idle;
        long total = user + nice + system + idle;
        long active = user + nice + system;
        int percentage = (active * 100) / total;
        return std::to_string(percentage) + "%";
    }
    return "N/A";
}
