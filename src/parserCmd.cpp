//
// parser.cpp for  in /home/hazer/plazza/src
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Tue Apr 11 17:16:02 2017 hazer
// Last update Sun Apr 30 18:59:09 2017 hazer
//

#include "parserCmd.hpp"
#include <unistd.h>

parserCmd::parserCmd()
{
  this->_exit = false;
  this->_didHelp = false;
}

parserCmd::~parserCmd()
{}

bool	parserCmd::getExit() const
{
  return (this->_exit);
}

bool	parserCmd::getHelp() const
{
  return (this->_didHelp);
}

std::list<std::string>	parserCmd::getHistoCmd() const
{
  return (this->_histoCmd);
}

std::list <std::pair<listStr, int> >  parserCmd::getCmd() const
{
  return (this->_execCmd);
}

void	parserCmd::fileChecker(listStr *tab)
{
  std::list<std::string>::iterator i;

  i = tab->begin();
  while (i != tab->end())
  {
    if ((access(i->c_str(), F_OK) == -1))
      {
	tab->erase(i++);
      }
    else
     i++;
  }
}

int	parserCmd::strToList(std::string const cmd)
{
  char const	*wordtab;
  std::string	str_epur;

  str_epur = epur_str(cmd);
  if (checkSemicolon(str_epur) == PLAZZA_ERR)
    return (PLAZZA_ERR);
  if ((wordtab = strtok((char*)str_epur.c_str(), ";")) == NULL)
    return (PLAZZA_ERR);
  while (wordtab != 0)
    {
      _listCmd.push_back(std::string(wordtab));
      _histoCmd.push_back(std::string(wordtab));
      wordtab = strtok(NULL, ";");
    }
  return (PLAZZA_OK);
}

int	parserCmd::execCmd()
{
  std::list<std::pair<listStr, int> >::const_iterator i;
  std::list<std::string>::const_iterator j;

  for (i = _execCmd.begin(); i != _execCmd.end(); ++i)
    {
      for (j = i->first.begin(); j != i->first.end(); ++j)
	{
	  if (*j == "help")
	    {
	      printHelp();
	      this->_didHelp = true;
	    }
	  else if (*j == "exit")
	    this->_exit = true;
	}
    }
  return (PLAZZA_OK);
}

bool	parserCmd::getType(listStr cmd, std::string type)
{
  const char *tmp;

  tmp = type.c_str();
  if (strncmp(tmp, "EMAIL_ADDRESS", 13) == 0)
    {
      _execCmd.push_back(make_pair(cmd, 2));
      return (true);
    }
  else if (strncmp(tmp, "IP_ADDRESS", 10) == 0)
    {
      _execCmd.push_back(make_pair(cmd, 3));
      return (true);
    }
  else if (strncmp(tmp, "PHONE_NUMBER", 12) == 0)
    {
      _execCmd.push_back(make_pair(cmd, 1));
      return (true);
    }
  std::cout << RED << "plazza: command not found" << BLANK << std::endl;
  return (false);
}

bool	parserCmd::isCmd(std::list<std::string>::const_iterator iterator)
{
  std::list<std::string>::const_iterator iterator_tmp;
  listStr	tmp;
  listStr	cpyTmp;
  std::string	str;
  const char	*cmd;
  const char	*wordtab;

  str = *iterator;
  cmd = str.c_str();
  std::string	cmd_line(cmd);
  if (strncmp(cmd, "exit", 4) == 0
      || strncmp(cmd, "help", 4) == 0)
    {
      tmp.push_back(cmd);
      _execCmd.push_back(make_pair(tmp, 0));
      return (true);
    }
  wordtab = strtok((char*)cmd, " ");
  while (cmd && wordtab != 0)
    {
      tmp.push_back(std::string(wordtab));
      wordtab = strtok(NULL, " ");
    }
  for (iterator_tmp = tmp.begin(); iterator_tmp != tmp.end(); ++iterator_tmp)
    cpyTmp.push_back(*iterator_tmp);
  cpyTmp.remove(cpyTmp.back());
  if (cpyTmp.empty() != false)
    {
      std::cerr << RED << "plazza: Wrong command." << BLANK << std::endl;
      return (false);
    }
  fileChecker(&cpyTmp);
  if (cpyTmp.empty() != false)
    {
      std::cerr << RED << "plazza: File(s) not found" << BLANK << std::endl;
      return (false);
    }
  if ((getType(cpyTmp, tmp.back())) == false)
    return (false);
  return (true);
}

int	parserCmd::readCmd()
{
  std::list<std::string>::const_iterator i;

  for (i = _listCmd.begin(); i != _listCmd.end(); ++i)
    {
      if ((isCmd(i)) == false)
	return (PLAZZA_ERR);
    }
  if (execCmd() == PLAZZA_ERR)
    return (PLAZZA_ERR);
  return (PLAZZA_OK);
}

void	parserCmd::clearList()
{
  _execCmd.clear();
  _listCmd.clear();
}

int	parserCmd::parseCmd(std::string str)
{
  this->_didHelp = false;
  if (strToList(str) == PLAZZA_ERR)
    {
      std::cerr << RED << "plazza: Wrong command." << BLANK << std::endl;
      return (PLAZZA_ERR);
    }
  if (readCmd() == PLAZZA_ERR)
    {
      clearList();
      return (PLAZZA_ERR);
    }
  return (PLAZZA_OK);
}
