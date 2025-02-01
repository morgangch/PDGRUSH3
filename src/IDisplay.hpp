/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include "../Krell.hpp"

class IDisplay : public Krell {
  public:
    virtual ~IDisplay() = default;
    virtual void draw() = 0;
  protected:
  private:
};

#endif /* !IDISPLAY_HPP_ */
