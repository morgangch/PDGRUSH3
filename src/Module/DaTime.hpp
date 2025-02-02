/*
** EPITECH PROJECT, 2025
** B-PDG-300-MPL-3-1-PDGRUSH3-morgan.guichard
** File description:
** DaTime
*/

#ifndef DATIME_HPP_
#define DATIME_HPP_

#include "../IModule.hpp"

class DaTime : public IModule {
  public:
    DaTime();
    ~DaTime();
    DataContainer *getDatas() override;
    std::string getDateTime() const;
    void update() override;

  private:
    std::string dateTime;
    void fetchData();
};

#endif /* !DATIME_HPP_ */
