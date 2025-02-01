/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DataManager.hpp
*/

#pragma once

enum DataType {
    Hostname,
    username,
    OS_name,
    kernel_version,
    Date,
    Hour,
    Minute,
    Second,
    Uptime,
    CPU,
    RAM,
    Swap,
    Disk,
    Network,
    Temperature,
    Fan,
    Voltage,
    Load,
    Process,
    User,
    Root
};

template <typename T> class Datadictionnary {
  public:
    Datadictionnary();
    ~Datadictionnary();
    T *data;
    DataType type;
    Datadictionnary *next;
};

class DataManager {
  public:
    DataManager();
    ~DataManager();

  protected:
  private:
};
