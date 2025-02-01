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

// void HostUser::draw(std::function<void(DataContainer*)> func)
// {
//     DataContainer *data(new DataContainer(2, 10, hostname));
//     func(data);
//     data->value = username;
//     data->x = 3;
//     data->y = 10;
//     func(data);
// }

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
    DataContainer *data(new DataContainer(0, 10, hostname));
    data->next = new DataContainer(0, 10, username);
    return data;
}