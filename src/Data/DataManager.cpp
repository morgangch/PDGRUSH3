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
    // setData(Uptime, getUptime());
    // setData(CPU, getCPU());
    // setData(RAM, getRAM());
    // setData(Swap, getSwap());
    // setData(Disk, getDisk());
    // setData(Network, getNetwork());
    // setData(Temperature, getTemperature());
    // setData(Fan, getFan());
    // setData(Voltage, getVoltage());
    // setData(Load, getLoad());
    // setData(Process, getProcess());
    // setData(User, getUser());
    // setData(Root, getRoot());
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
//     return 0;
// }