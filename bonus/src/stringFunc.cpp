//
// stringFunc.cpp for  in /home/hazer/plazza/src
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Wed Apr 12 13:26:45 2017 hazer
// Last update Sun Apr 30 14:50:48 2017 Jean-Baptiste Colette
//

#include <plazza.hpp>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

std::string	epur_str(std::string str)
{
  std::istringstream iss(str);
  std::string w, result;

  if (iss >> w)
    result += w;
  while (iss >> w)
    result += ' ' + w;
  return (result);
}

void	printList(std::list<std::string> s)
{
  std::list<std::string>::const_iterator i;

  for (i = s.begin(); i != s.end(); ++i)
    std::cout << *i << std::endl;
}

int	checkSemicolon(std::string str)
{
  for(std::string::size_type i = 0; i < str.length(); ++i)
    {
      if (str[i] == ';' && str[i+1] == ';')
	return (PLAZZA_ERR);
    }
  return (PLAZZA_OK);
}

void	printHelp()
{
  std::cout << CYAN << "Usage   :" << BLUE << "\t./plazza [number_of_threads_per_process]\n" << BLANK << std::endl;
  std::cout << CYAN << "Commands:" << BLUE << "\n\thelp\t\t\tDisplay this help\n\t[FILE] PHONE_NUMBER\tDisplay the phone numbers in the file" << std::endl;
  std::cout << "\t[FILE] EMAIL_ADDRESS\tDisplay the mail address in the file\n\t[FILE] IP_ADDRESS\tDisplay the IP address in the file" << std::endl;
  std::cout << "\texit\t\t\tQuit the plazza" << BLANK << std::endl;
}
