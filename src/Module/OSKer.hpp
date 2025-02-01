/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** OSKer
*/

#ifndef OSKER_HPP_
#define OSKER_HPP_

#include "../IModule.hpp"
#include <string>

class OSKer : public IModule {
    public:
        OSKer();
        ~OSKer();
        void draw(std::function<void(DataContainer*)> func) override;
        std::string getOSName() const;
        std::string getKernelVersion() const;

    private:
        std::string osName;
        std::string kernelVersion;
        void fetchData();
};

#endif /* !OSKER_HPP_ */
