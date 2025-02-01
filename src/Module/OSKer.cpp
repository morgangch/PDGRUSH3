/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** OSKer
*/

#include "OSKer.hpp"
#include <iostream>
#include <sys/utsname.h>

OSKer::OSKer()
{
    fetchData();
}

OSKer::~OSKer() {}

void OSKer::fetchData()
{
    struct utsname buffer;

    if (uname(&buffer) == 0) {
        osName = buffer.sysname;
        kernelVersion = buffer.release;
    } else {
        osName = "Unknown";
        kernelVersion = "Unknown";
    }
}

// void OSKer::draw(std::function<void(DataContainer*)> func)
// {
//     DataContainer *data(new DataContainer(2, 10, osName));
//     func(data);
//     data->value = kernelVersion;
//     data->x = 3;
//     data->y = 10;
//     func(data);
// }

std::string OSKer::getOSName() const
{
    return osName;
}

std::string OSKer::getKernelVersion() const
{
    return kernelVersion;
}

DataContainer *OSKer::getDatas()
{
    fetchData();
    DataContainer *data(new DataContainer(0, 10, osName));
    data->next = new DataContainer(0, 10, kernelVersion);
    return data;
}