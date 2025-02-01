/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** IModule
*/

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include "Krell.hpp"
#include "DataContainer.hpp"
#include <functional>

class Coordinates {
  public:
    Coordinates(int x = 0, int y = 0) : x(x), y(y){};
    ~Coordinates() = default;
    int x;
    int y;

  protected:
  private:
};

class IModule : public Krell {
  public:
    IModule();
    ~IModule();
    virtual void draw(std::function<void(DataContainer*)> func) = 0;
    Coordinates top_left;
    Coordinates bottom_right;
    int width;
    int height;

  protected:
  private:
};

#endif /* !IMODULE_HPP_ */
