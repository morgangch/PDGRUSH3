/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** main
*/

#include "Krell.hpp"
#include "src/Supervisor.hpp"

int main(int ac, char **av)
{
    if (ac < 1)
        return 84;
    if (av[1] == "--tui")
        supervisor(1);
    supervisor(0);
    return 0;
}
