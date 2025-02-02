/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** main
*/

#include "Krell.hpp"
#include "src/Supervisor.hpp"
#include "src/Module/Cpu.hpp"


int main(int ac, char **av)
{
    if (ac == 1)
        supervisor(false);
    if (ac < 2)
        return 84;
    if (std::string(av[1]) == "--tui")
        supervisor(true);
    return 0;
}
