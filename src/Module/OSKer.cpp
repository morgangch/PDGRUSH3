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
    DataContainer *data(new DataContainer(0, 0, osName));
    data->next = new DataContainer(0, 0, kernelVersion);
    return data;
}