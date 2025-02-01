/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DaTime
*/

#ifndef DATIME_HPP_
#define DATIME_HPP_

#include "../IModule.hpp"
#include <string>
#include <functional>

class DaTime : public IModule {
  public:
    DaTime();
    ~DaTime();
    DataContainer *getDatas();
    std::string getDateTime() const;

  private:
    std::string dateTime;
    void fetchData();
};

#endif /* !DATIME_HPP_ */
