//
// parserFile.hpp for  in /home/hazer/cpp_plazza/include
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Fri Apr 21 12:05:31 2017 hazer
// Last update Sun Apr 30 13:19:53 2017 Jean-Baptiste Colette
//

#ifndef	_PARSER_FILE_HPP_
# define _PARSER_FILE_HPP_

#include "task.hpp"
#include "parserCmd.hpp"
#include <iostream>
#include <regex>
#include <fstream>
#include <mutex>


#define	EMAIL_REGEX	"(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|\"(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21\\x23-\\x5b\\x5d-\\x7f]|\\\\[\
\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])*\")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0\
-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21-\\x5a\\x53-\\x7f]|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])+)\\])"
#define PHONE_REGEX	"(0[1-9][[:space:]]?)([[:digit:]]{2}[[:space:]]?){4}"
#define IP_REGEX	"(?:(?:0|1[\\d]{0,2}|2(?:[0-4]\\d?|5[0-5]?|[6-9])?|[3-9]\\d?)\\.){3}(?:0|1[\\d]{0,2}|2(?:[0-4]\\d?|5[0-5]?|[6-9])?|[3-9]\\d?)"

class	parserFile
{
public:
  parserFile(int nbThreads);
  ~parserFile();

  void	setCmd(std::list <std::pair <listStr, int> > _execCmd);
  std::list <std::pair<listStr, int> >	getCmd() const;
  void	printThreads();
  void	myfork(std::string name, int cmd);
  void	taskmanager(std::string name, int cmd);
  void	find_regex(std::string line);
  void	parserRegex(Task *task);
  void	collectData(const std::string str, std::regex to_search);
  void	bruteforceXor(std::string line, std::smatch m, std::regex to_search);
  void	bruteforceCaesar(std::string line, std::smatch m, std::regex to_search);
  void  clientPipe();
  void  serverPipe();

private:
  std::mutex mtx;
  int		_nbThreads;
  std::list <std::pair<listStr, int> >  _command;
  std::string	collectedData;
  std::ofstream logfile;
};

#endif	/* _PARSER_FILE_HPP*/
