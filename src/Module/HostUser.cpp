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
    hostname = "Hostname: " + std::string(host);

    struct passwd *pw = getpwuid(getuid());
    username = (pw) ? std::string(pw->pw_name) : "Unknown";
    username = "Username: " + username;
}

std::string HostUser::getHostname() const
{
    return hostname;
}

std::string HostUser::getUsername() const
{
    return username;
}

DataContainer *HostUser::getDatas()
{
    fetchData();
    DataContainer *data(new DataContainer(0, 0, hostname));
    data->next = new DataContainer(0, 0, username);
    return data;
}