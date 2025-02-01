/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include "../Krell.hpp"
#include "./Module/HostUser.hpp"
#include "./Module/OSKer.hpp"
#include "./Module/DaTime.hpp"
#include "./Module/Cpu.hpp"
#include "./Module/Ram.hpp"

enum ExitReason {
    EXIT,
    CHANGE_LIB,
    NONE
};

class IDisplay : public Krell {
  public:
    virtual ~IDisplay() = default;
    virtual void draw() = 0;
    virtual void Init() = 0;
    virtual ExitReason subLoop() = 0;
  protected:
      HostUser hostUser;
      OSKer osKer;
      DaTime daTime;
      CPU cpu;
      RAM ram;
  private:
};

#endif /* !IDISPLAY_HPP_ */
