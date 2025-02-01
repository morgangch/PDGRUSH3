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

template <typename T>
class Datadictionnary {
  public:
    Datadictionnary();
    Datadictionnary(T data, DataType type);
    ~Datadictionnary();
    T *data;
    DataType type;
    Datadictionnary *next;
};

template <typename T>
class DataManager {
  public:
    DataManager();
    ~DataManager();
    void addData(DataType type, T data);
    void removeData(DataType type);
    void setData(DataType type, T data);
    T getData(DataType type);

  protected:
  private:
    Datadictionnary<T> *_data;
};
