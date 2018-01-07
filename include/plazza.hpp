//
// plazza.hpp for  in /home/hazer/plazza/include
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Tue Apr 11 10:53:00 2017 hazer
// Last update Fri Apr 21 12:20:23 2017 hazer
//

#ifndef _PLAZZA_HPP_
# define _PLAZZA_HPP_

#include <utils.hpp>
#include "parserCmd.hpp"
#include "parserFile.hpp"

namespace	Plazza
{
  enum Information
    {
      PHONE_NUMBER = 1,
      EMAIL_ADDRESS = 2,
      IP_ADDRESS = 3
    };

  class	Core
  {
  public:
    Core();
    ~Core();
    int		initPlazza(int nbThreads);

  private:
    int		_nbThreads;
    std::string	_cmd;
  };
}

#endif /* _PLAZZA_HPP_ */
