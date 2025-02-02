/*
** EPITECH PROJECT, 2025
** PDGRUSH3
** File description:
** Powder
*/

#ifndef POWER_HPP_
#define POWER_HPP_

#include "../IModule.hpp"

class Power : public IModule {
    public:
        Power();
        ~Power();

        DataContainer *getDatas() override;
        void update() override;

    private:
        std::string _power;
        std::string _buildInfos;
};

#endif /* !POWDER_HPP_ */
