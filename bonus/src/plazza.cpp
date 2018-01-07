//
// plazza.cpp for  in /home/hazer/plazza/src
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Tue Apr 11 15:48:20 2017 hazer
// Last update Sun Apr 30 17:10:08 2017 Jean-Baptiste Colette
//

#include "plazza.hpp"
#include "parserCmd.hpp"
#include "parserFile.hpp"

Plazza::Core::Core()
{}

Plazza::Core::~Core()
{}

int	Plazza::Core::initPlazza(int nbThreads)
{
  parserCmd	cmd;
  parserFile	file(nbThreads);
  int		i = 0;

  std::cout << YELLOW << "\tWelcome to the plazza\n" << BLANK << std::endl;
  std::cout << BROWN << "-Enter \"help\" to display help." <<BLANK << std::endl;
  std::cout << GREEN << " [0] $> " << BLANK;
  while (cmd.getExit() == false && std::getline(std::cin, _cmd))
    {
      if (_cmd.empty() == false)
	{
	  if ((cmd.parseCmd(this->_cmd)) == PLAZZA_OK
	      && cmd.getExit() == false && cmd.getLaunchedCmd() == false)
	    {
	      file.setCmd(cmd.getCmd());
	      file.printThreads();
	    }
	  cmd.clearList();
	}
      if (cmd.getExit() == false)
	std::cout << GREEN << " [" << ++i << "] $> " << BLANK;
    }
  return (PLAZZA_OK);
}
