/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DaTime
*/

#include "DaTime.hpp"
#include <iostream>
#include <ctime>
#include "DataContainer.hpp"

DaTime::DaTime()
{
    fetchData();
}

DaTime::~DaTime() {}

void DaTime::fetchData()
{
    std::time_t now = std::time(nullptr);
    char buf[80];
    std::strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", std::localtime(&now));
    dateTime = buf;
}

std::string DaTime::getDateTime() const
{
    return dateTime;
}

DataContainer *DaTime::getDatas()
{
    fetchData();
    DataContainer *data(new DataContainer(0, 10, dateTime));
    return data;
}

void DaTime::update()
{
    fetchData();
}
