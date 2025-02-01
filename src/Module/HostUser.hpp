/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** HostUser
*/

#ifndef HOSTUSER_HPP_
#define HOSTUSER_HPP_

#include "../IModule.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

class HostUser : public IModule {
    public:
        HostUser();
        ~HostUser();
        void draw(std::function<void(DataContainer*)> func) override;
        std::string getHostname() const;
        std::string getUsername() const;

    private:
        std::string hostname;
        std::string username;
        void fetchData();
};

#endif /* !HOSTUSER_HPP_ */
