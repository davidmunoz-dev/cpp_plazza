//
// main.cpp for  in /home/hazer/plazza/src
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Tue Apr 11 10:51:49 2017 hazer
// Last update Sun Apr 30 00:28:08 2017 hazer
//

#include "plazza.hpp"

int	check_args(int ac, char **av)
{
  if (ac != 2 || atoi(av[1]) <= 0)
    {
      std::cerr << RED << "Usage : ./plazza [threads_per_process]" << std::endl;
      std::cerr << "\tArgument should be an unsigned number." << BLANK << std::endl;
      return (PLAZZA_ERR);
    }
  return (PLAZZA_OK);
}

int	main(int ac, char **av)
{
  Plazza::Core	*plazza = NULL;

  if (check_args(ac, av) == PLAZZA_ERR)
    return (PLAZZA_ERR);
  plazza = new Plazza::Core();

  if ((plazza->initPlazza(atoi(av[1]))) == PLAZZA_ERR)
    return (PLAZZA_ERR);
  delete plazza;
  return (PLAZZA_OK);
}
