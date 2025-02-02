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
    ;
}

DataContainer *Power::getDatas()
{
    DataContainer *data(new DataContainer(0, 0, _power));
    return data;
}

void Power::update()
{
    std::string pow;
    std::string status;

    std::ifstream file("/sys/class/power_supply/BAT1/capacity");
    if (file.is_open()) {
        file >> pow;
        pow = "Battery: " + pow + "%";
        file.close();
    } else {
        pow = std::string("Battery: N/A");
    }
    std::ifstream file0("/sys/class/power_supply/BAT1/status");
    if (file0.is_open()) {
        file0 >> status;
        file0.close();
    } else {
        status = std::string("Status: N/A");
    }
    _power = pow + " " + status + "   \n" + _buildInfos;
}
