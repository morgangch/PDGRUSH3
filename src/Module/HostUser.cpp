/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** HostUser
*/

#include "HostUser.hpp"
#include <iostream>

HostUser::HostUser()
{
    fetchData();
}

HostUser::~HostUser() {}

void HostUser::fetchData()
{
    char host[256];
    gethostname(host, sizeof(host));
    hostname = std::string(host);

    struct passwd *pw = getpwuid(getuid());
    username = (pw) ? std::string(pw->pw_name) : "Unknown";
}

void HostUser::display()
{
    std::cout << "Hostname: " << hostname << "\nUsername: " << username << std::endl;
}

void HostUser::draw()
{
    display();
}

std::string HostUser::getHostname() const
{
    return hostname;
}

std::string HostUser::getUsername() const
{
    return username;
}
