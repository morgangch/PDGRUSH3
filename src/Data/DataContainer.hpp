/*
** EPITECH PROJECT, 2025
** PDGRUSH3
** File description:
** DataContainer
*/

#ifndef DATACONTAINER_HPP_
#define DATACONTAINER_HPP_

#include <iostream>
#include <string>

class DataContainer {
    public:
        DataContainer(int x = 0, int y = 0, const std::string &value = std::string(), int a_size = 1) : x(x), y(y), size(a_size), value(const_cast<std::string&>(value)), next(nullptr) {};
        DataContainer() = default;
        ~DataContainer() = default;
        int x;
        int y;
        int size;
        std::string &value;
        DataContainer *next;
    protected:
    private:
};

#endif /* !DATACONTAINER_HPP_ */
