/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DataManager.hpp
*/

#include "DataManager.hpp"

// Fonctions for the Datadictionnary class

Datadictionnary::Datadictionnary(std::string data, DataType type)
{
    this->data = data;
    this->type = type;
    next = nullptr;
}

Datadictionnary::~Datadictionnary()
{
}


// Fonctions for the DataManager class

DataManager::DataManager()
{
    _data = nullptr;
    getDatavalues();
}

DataManager::~DataManager()
{
    Datadictionnary *tmp = _data;
    while (tmp) {
        Datadictionnary *next = tmp->next;
        delete tmp;
        tmp = next;
    }
}

void DataManager::addData(DataType type, std::string data)
{
    Datadictionnary *newData = new Datadictionnary(data, type);
    Datadictionnary *tmp = _data;
    while (tmp && tmp->next) {
        tmp = tmp->next;
    }
    if (tmp)
        tmp->next = newData;
    else
        _data = newData;
}

void DataManager::removeData(DataType type)
{
    Datadictionnary *tmp = _data;
    Datadictionnary *prev = nullptr;
    while (tmp && tmp->type != type) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp)
        return;
    if (prev)
        prev->next = tmp->next;
    else
        _data = tmp->next;
    delete tmp;
}

void DataManager::setData(DataType type, std::string data)
{
    Datadictionnary *tmp = _data;
    while (tmp && tmp->type != type) {
        tmp = tmp->next;
    }
    if (!tmp) {
        addData(type, data);
        return;
    }
    tmp->data = data;
}

std::string DataManager::getData(DataType type)
{
    Datadictionnary *tmp = _data;
    while (tmp && tmp->type != type) {
        tmp = tmp->next;
    }
    if (!tmp)
        return nullptr;
    return tmp->data;
}

void DataManager::Refresh()
{
    getDatavalues();
}

void DataManager::getDatavalues()
{
    setData(Hostname, getHostname());
    setData(username, getUsername());
    setData(OS_name, getOSName());
    setData(kernel_version, getKernelVersion());
    setData(Date, getDate());
    setData(Hour, getHour());
    setData(Minute, getMinute());
    setData(Second, getSecond());
    setData(CPUModel, getCPUModel());
    setData(CPUCores, getCPUCores());
    setData(CPUFrequency, getCPUFrequency());
    setData(CPUUsage, getCPUUsage());
    setData(TotalRAM, getTotalRAM());
    setData(FreeRAM, getFreeRAM());
    setData(UsedRAM, getUsedRAM());
}

std::string DataManager::getHostname()
{
    char hostname[1024];
    gethostname(hostname, 1024);
    return hostname;
}

std::string DataManager::getUsername()
{
    struct passwd *pw = getpwuid(getuid());
    return (pw) ? std::string(pw->pw_name) : "Unknown";
}

std::string DataManager::getOSName()
{
    struct utsname buffer;

    if (uname(&buffer) == 0) {
        return buffer.sysname;
    } else {
        return "Unknown";
    }
}

std::string DataManager::getKernelVersion()
{
    struct utsname buffer;

    if (uname(&buffer) == 0) {
        return buffer.release;
    } else {
        return "Unknown";
    }
}

std::string DataManager::getDate()
{
    std::time_t t = std::time(nullptr);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&t));
    return std::string(buffer);
}

std::string DataManager::getHour()
{
    std::time_t t = std::time(nullptr);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%H", std::localtime(&t));
    return std::string(buffer);
}

std::string DataManager::getMinute()
{
    std::time_t t = std::time(nullptr);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%M", std::localtime(&t));
    return std::string(buffer);
}

std::string DataManager::getSecond()
{
    std::time_t t = std::time(nullptr);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%S", std::localtime(&t));
    return std::string(buffer);
}

std::string DataManager::getCPUModel()
{
    std::ifstream cpuInfo("/proc/cpuinfo");
    std::string line;

    while (std::getline(cpuInfo, line)) {
        if (line.find("model name") != std::string::npos)
            return line.substr(line.find(":") + 2);
    }
    return "Unknown CPU Model";
}

std::string DataManager::getCPUCores()
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

std::string DataManager::getCPUFrequency()
{
    std::ifstream cpuInfo("/proc/cpuinfo");
    std::string line;

    while (std::getline(cpuInfo, line)) {
        if (line.find("cpu MHz") != std::string::npos)
            return line.substr(line.find(":") + 2) + " MHz";
    }
    return "Unknown Frequency";
}

std::string DataManager::getCPUUsage()
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
    return "Unknown";
}

std::string DataManager::getTotalRAM()
{
    std::ifstream memInfo("/proc/meminfo");
    std::string line;

    while (std::getline(memInfo, line)) {
        if (line.find("MemTotal") != std::string::npos)
            return line.substr(line.find(":") + 2);
    }
    return "Unknown";
}

std::string DataManager::getFreeRAM()
{
    std::ifstream memInfo("/proc/meminfo");
    std::string line;

    while (std::getline(memInfo, line)) {
        if (line.find("MemFree") != std::string::npos)
            return line.substr(line.find(":") + 2);
    }
    return "Unknown";
}

std::string DataManager::getUsedRAM()
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

// int main()
// {
//     DataManager dataManager;
//     dataManager.Refresh();
//     std::cout << dataManager.getData(Hostname) << std::endl;
//     std::cout << dataManager.getData(username) << std::endl;
//     std::cout << dataManager.getData(OS_name) << std::endl;
//     std::cout << dataManager.getData(kernel_version) << std::endl;
//     std::cout << dataManager.getData(Date) << std::endl;
//     std::cout << dataManager.getData(Hour) << std::endl;
//     std::cout << dataManager.getData(Minute) << std::endl;
//     std::cout << dataManager.getData(Second) << std::endl;
//     std::cout << dataManager.getData(CPUModel) << std::endl;
//     std::cout << dataManager.getData(CPUCores) << std::endl;
//     std::cout << dataManager.getData(CPUFrequency) << std::endl;
//     std::cout << dataManager.getData(CPUUsage) << std::endl;
//     std::cout << dataManager.getData(TotalRAM) << std::endl;
//     std::cout << dataManager.getData(FreeRAM) << std::endl;
//     std::cout << dataManager.getData(UsedRAM) << std::endl;
//     return 0;
// }