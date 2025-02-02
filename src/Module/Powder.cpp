/*
** EPITECH PROJECT, 2025
** PDGRUSH3
** File description:
** Powder
*/

#include "Powder.hpp"

Power::Power()
{
    update();
    std::string manuf;
    std::string model;

    std::ifstream file("/sys/class/power_supply/BAT1/manufacturer");
    if (file.is_open()) {
        file >> manuf;
        file.close();
    } else {
        manuf = std::string("Manufacturer: N/A");
    }
    std::ifstream file0("/sys/class/power_supply/BAT1/model_name");
    if (file0.is_open()) {
        file0 >> model;
        file0.close();
    } else {
        model = std::string("Model: N/A");
    }
    _buildInfos = "Manufacturer/Model: " + manuf + "/" + model;
}

Power::~Power()
{
}

DataContainer *Power::getDatas()
{
    DataContainer *data(new DataContainer(0, 0, _power, 4));
    return data;
}

std::string Power::findBatteryPath()
{
    for (const auto& entry : std::filesystem::directory_iterator("/sys/class/power_supply/")) {
        if (entry.is_directory()) {
            std::string path = entry.path().string();
            std::ifstream typeFile(path + "/type");
            std::string type;
            if (typeFile.is_open()) {
                typeFile >> type;
                typeFile.close();
                if (type == "Battery") {
                    return path;
                }
            }
        }
    }
    return "";
}

bool Power::readFile(const std::string& filePath, int& value)
{
    std::ifstream file(filePath);
    if (file.is_open()) {
        file >> value;
        file.close();
        return true;
    }
    return false;
}

bool Power::readFile(const std::string& filePath, std::string& value)
{
    std::ifstream file(filePath);
    if (file.is_open()) {
        file >> value;
        file.close();
        return true;
    }
    return false;
}

void Power::update()
{
    if (_batteryPath.empty()) {
        _batteryPath = findBatteryPath();
        if (_batteryPath.empty()) {
            std::cerr << "No battery found!" << std::endl;
            return;
        }
    }

    readFile(_batteryPath + "/capacity", _capacity);
    readFile(_batteryPath + "/status", _status);
    readFile(_batteryPath + "/energy_now", _energyNow) || readFile(_batteryPath + "/charge_now", _energyNow);
    readFile(_batteryPath + "/energy_full", _energyFull) || readFile(_batteryPath + "/charge_full", _energyFull);
    readFile(_batteryPath + "/power_now", _powerNow);
    _power = "Capacity: " + std::to_string(_capacity) + "%\nStatus: " + _status + "\nEnergy: " + std::to_string(_energyNow) + " / " + std::to_string(_energyFull) + " mWh\nPower: " + std::to_string(_powerNow) + " mW";
}