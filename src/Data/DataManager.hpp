/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DataManager.hpp
*/

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <algorithm>
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <ctime>
#include <fstream>
#include <sstream>

enum DataType {
    Hostname,
    username,
    OS_name,
    kernel_version,
    Date,
    Hour,
    Minute,
    Second,
    CPUModel,
    CPUCores,
    CPUFrequency,
    CPUUsage,
    TotalRAM,
    FreeRAM,
    UsedRAM
};

class Datadictionnary {
  public:
    Datadictionnary(std::string data, DataType type);
    ~Datadictionnary();
    std::string data;
    DataType type;
    Datadictionnary *next;
};

class DataManager {
  public:
    DataManager();
    ~DataManager();
    void addData(DataType type, std::string data);
    void removeData(DataType type);
    void setData(DataType type, std::string data);
    std::string getData(DataType type);
    void getDatavalues();
    void Refresh();

  protected:
  private:
    Datadictionnary *_data;
    std::string getHostname();
    std::string getUsername();
    std::string getOSName();
    std::string getKernelVersion();
    std::string getDate();
    std::string getHour();
    std::string getMinute();
    std::string getSecond();
    std::string getCPUModel();
    std::string getCPUCores();
    std::string getCPUFrequency();
    std::string getCPUUsage();
    std::string getTotalRAM();
    std::string getFreeRAM();
    std::string getUsedRAM();
};
