//
// task.hpp for  in /home/hazer/cpp_plazza/include
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Wed Apr 26 13:55:52 2017 hazer
// Last update Sun Apr 30 01:00:41 2017 Jean-Baptiste Colette
//

#ifndef _TASK_HPP_
# define _TASK_HPP_

#include "utils.hpp"

class Task
{
public:
  std::string line;
  int cmd;
  Task(std::string line, int cmd);
  ~Task();
};

#endif /* _TASK_HPP_ */
