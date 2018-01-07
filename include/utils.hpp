//
// utils.hpp for  in /home/hazer/cpp_plazza/include
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Fri Apr 14 12:29:50 2017 hazer
// Last update Sun Apr 30 14:51:24 2017 Jean-Baptiste Colette
//

#ifndef	_UTILS_HPP_
# define _UTILS_HPP_

#include <list>
#include <iostream>
#include <cstring>
#include <cstdlib>

#define PLAZZA_ERR      -1
#define PLAZZA_OK       0
#define PLAZZA_CMD_OK   1
#define PLAZZA_CMD_ERR  2

#define RED             "\033[1;31m"
#define GREEN           "\033[1;32m"
#define PURPLE          "\033[1;35m"
#define CYAN            "\033[1;36m"
#define BROWN           "\033[0;33m"
#define BLUE            "\033[1;34m"
#define YELLOW          "\033[1;33m"
#define BLANK           "\033[0m"

void		printList(std::list<std::string> s);
std::string	epur_str(std::string str);
void		printHelp();
std::string	decryptCaesar(std::string source, unsigned short key);
std::string	decryptXor(std::string line, unsigned short key);
int	checkSemicolon(std::string str);

#endif /* _UTILS_HPP_ */
