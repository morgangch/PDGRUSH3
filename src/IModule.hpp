/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** IModule
*/

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include <functional>
#include <string>
#include "DataContainer.hpp"
#include "Krell.hpp"

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
    Coordinates top_left;
    Coordinates bottom_right;
    int width;
    int height;
    virtual DataContainer *getDatas() = 0;
    virtual void update() = 0;
  protected:
  private:
};

#endif /* !IMODULE_HPP_ */
