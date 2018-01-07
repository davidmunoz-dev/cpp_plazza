//
// task.cpp for  in /home/hazer/cpp_plazza/src
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Wed Apr 26 13:57:38 2017 hazer
// Last update Sun Apr 30 01:01:15 2017 Jean-Baptiste Colette
//

#include "task.hpp"
#include "utils.hpp"

Task::Task(std::string line, int cmd)
{
  this->line = line;
  this->cmd = cmd;
}

Task::~Task()
{}
