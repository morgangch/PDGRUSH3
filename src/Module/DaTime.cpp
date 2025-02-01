/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DaTime
*/

#include "DaTime.hpp"
#include <iostream>
#include <ctime>

DaTime::DaTime()
{
    fetchData();
}

DaTime::~DaTime() {}

void DaTime::fetchData()
{
    std::time_t t = std::time(nullptr);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
    dateTime = std::string(buffer);
}

void DaTime::display()
{
    std::cout << "Date & Time: " << dateTime << std::endl;
}

void DaTime::draw()
{
    display();
}

std::string DaTime::getDateTime() const
{
    return dateTime;
}
