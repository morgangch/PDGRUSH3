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

void OSKer::display()
{
    std::cout << "OS: " << osName << "\nKernel: " << kernelVersion << std::endl;
}

void OSKer::draw()
{
    display();
}

std::string OSKer::getOSName() const
{
    return osName;
}

std::string OSKer::getKernelVersion() const
{
    return kernelVersion;
}
