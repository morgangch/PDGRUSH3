/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** CPU
*/

#include "Cpu.hpp"
#include <fstream>
#include <sstream>

CPU::CPU()
{
    update();
}

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
    std::getline(file, line);
    std::istringstream ss(line);

    std::string cpu;
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    ss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

    long totalIdle = idle + iowait;
    long totalNonIdle = user + nice + system + irq + softirq + steal;
    long total = totalIdle + totalNonIdle;

    static long prevTotal = 0;
    static long prevIdle = 0;

    long totald = total - prevTotal;
    long idled = totalIdle - prevIdle;

    prevTotal = total;
    prevIdle = totalIdle;

    float cpuUsage = 0.0;
    if (totald != 0) {
        cpuUsage = (totald - idled) * 100.0 / totald;
    }
    std::ostringstream oss;
    oss.precision(2);
    oss << std::fixed << cpuUsage;
    return oss.str();
}

DataContainer *CPU::getDatas()
{
    DataContainer *data(new DataContainer(0, 0, _format, 1));

    return data;
}

void CPU::update()
{
    _model = getCPUModel();
    _cores = getCPUCores();
    _frequency = getCPUFrequency();
    _usage = getCPUUsage();
    _format = "CPU: " + _model + " - " + _cores + " cores\n     " + _usage + "% - " + _frequency;
}
