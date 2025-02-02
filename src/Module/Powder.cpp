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
    std::ifstream file("/sys/class/power_supply/BAT1/capacity");
    if (file.is_open()) {
        file >> _power;
        _power = "Battery: " + _power + "%";
        file.close();
    } else {
        _power = std::string("Battery: N/A");
    }
}
