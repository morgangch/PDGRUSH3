/*
** EPITECH PROJECT, 2025
** PDGRUSH3
** File description:
** Powder
*/

#ifndef POWER_HPP_
#define POWER_HPP_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "../IModule.hpp"

class Power : public IModule {
  public:
    Power();
    ~Power();
    DataContainer *getDatas() override;
    void update() override;

  private:
    std::string _power;
    std::string _batteryPath;
    std::string _status = "Unknown";
    std::string _buildInfos;
    int _capacity = -1;
    int _energyNow = -1;
    int _energyFull = -1;
    int _powerNow = -1;

    std::string findBatteryPath();
    bool readFile(const std::string &filePath, int &value);
    bool readFile(const std::string &filePath, std::string &value);

};

#endif /* !POWDER_HPP_ */
