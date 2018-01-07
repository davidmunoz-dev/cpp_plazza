//
// parser.hpp for  in /home/hazer/plazza/include
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Tue Apr 11 17:12:51 2017 hazer
// Last update Sun Apr 30 15:14:05 2017 Jean-Baptiste Colette
//

#ifndef	_PARSER_CMD_HPP_
# define _PARSER_CMD_HPP_

#include <utils.hpp>
#include <list>
#include <iostream>
#include <utility>
#include <functional>
#include <vector>

typedef std::list<std::string>	listStr;

class	parserCmd
{
public:
  parserCmd();
  ~parserCmd();

  int	parseCmd(std::string str);
  bool	isCmd(std::list<std::string>::const_iterator);
  bool	getType(listStr cmd, std::string);
  int	readCmd();
  int	execCmd();
  int	strToList(std::string const cmd);
  bool	getExit() const;
  bool	getHelp() const;
  void	clearList();
  void	fileChecker(listStr*);
  std::list<std::string>	getHistoCmd() const;
  std::list <std::pair<listStr, int> >  getCmd() const;

private:
  bool			_didHelp;
  listStr		_listCmd;
  listStr		_histoCmd;
  std::list <std::pair<listStr, int> >	_execCmd;
  bool			_exit;
};

#endif /* _PARSER_CMD_HPP_ */
