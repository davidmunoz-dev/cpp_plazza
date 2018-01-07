//
// parserFile.cpp for  in /home/hazer/cpp_plazza/src
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Fri Apr 21 12:03:41 2017 hazer
// Last update Sun Apr 30 16:04:13 2017 Jean-Baptiste Colette
//

#include <unistd.h>
#include "parserFile.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <vector>
#include <thread>
#include <unistd.h>
#include <signal.h>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <wait.h>

parserFile::parserFile(int nbThreads)
{
  this->_nbThreads = nbThreads;
  collectedData = "";
}

parserFile::~parserFile()
{}

void	parserFile::collectData(std::string str, std::regex to_search)
{
  const std::sregex_token_iterator end;
  for (std::sregex_token_iterator it(str.begin(), str.end(), to_search); it != end; ++it)
    {
      this->collectedData += *it;
      this->collectedData.push_back('\n');
    }
}

void	parserFile::setCmd(std::list <std::pair<listStr, int> > _execCmd)
{
  this->_command = _execCmd;
}

std::list <std::pair<listStr, int> >	parserFile::getCmd() const
{
  return (this->_command);
}

void	parserFile::bruteforceXor(const std::string line, std::smatch m, std::regex to_search)
{
  std::string		lineUnciphered;
  unsigned short	key;

  for (key = 1; key < 65535; key++)
    {
      lineUnciphered = decryptXor(line, key);
      if (std::regex_search(lineUnciphered, m, to_search))
	{
	  collectData(lineUnciphered, to_search);
	  return;
	}
    }
}

void	parserFile::bruteforceCaesar(std::string line, std::smatch m, std::regex to_search)
{
  std::string		lineUnciphered;
  unsigned short	key;

  for (key = 1; key < 255; key++)
    {
      lineUnciphered = decryptCaesar(line, key);
      if (std::regex_search(lineUnciphered, m, to_search))
	{
	  collectData(lineUnciphered, to_search);
	  return;
	}
    }
}

void	parserFile::parserRegex(Task *task)
{
  std::regex    email(EMAIL_REGEX);
  std::regex    phone(PHONE_REGEX);
  std::regex    ip_adress(IP_REGEX);
  std::regex    to_search;
  std::smatch   m;

  this->mtx.lock();
  if (task->cmd == 1)
    to_search = phone;
  else if (task->cmd == 2)
    to_search = email;
  else if (task->cmd == 3)
    to_search = ip_adress;
  if (std::regex_search(task->line, m, to_search))
    collectData(task->line, to_search);
   else
    {
      if (collectedData.empty() == true)
	bruteforceXor(task->line, m, to_search);
      if (collectedData.empty() == true)
	bruteforceCaesar(task->line, m, to_search);
    }
  delete(task);
  this->mtx.unlock();
}

void    parserFile::taskmanager(std::string name, int cmd)
{
  std::string line;
  std::ifstream infile(name);
  std::thread *threads = new std::thread[this->_nbThreads];
  int i = 0;

  while (std::getline(infile, line))
    {
      if (i == this->_nbThreads)
	{
	  for (i = 0; i != this->_nbThreads; i++)
	    threads[i].join();
	  i = 0;
	}
      Task *task = new Task(line, cmd);
      threads[i++] = std::thread(&parserFile::parserRegex, this, task);
    }
  for (i = 0; i == this->_nbThreads; i++)
    if (threads[i].joinable())
      threads[i].join();
}
  
  void	parserFile::clientPipe()
{
  int client;

  if ((client = open("/tmp/server_fifo", O_WRONLY)) == -1)
    {
      perror("Open");
      exit(-1);
    }
  if (write(client, (char *)this->collectedData.c_str(), this->collectedData.size()) < 0)
    {
      perror("Write");
      exit(-1);
    }
  close(client);
  exit(-1);
}

void	parserFile::serverPipe()
{
  int server;
  char buf[BUFSIZ];

  server = open("/tmp/server_fifo", O_RDONLY);
  if ((read(server, buf, BUFSIZ)) == -1)
    close (server);
  if (strcmp("",buf)!=0)
    {
      std::cout << buf;
      if (this->logfile.is_open())
	this->logfile << buf << std::endl;
    }
  memset(buf, 0, sizeof(buf));
  close (server);
}

static std::string	intToCmdType(int type)
{
  std::string	str_type;
  
  if (type == 1)
    str_type = "PHONE_NUMBER";
  else if (type == 2)
    str_type = "EMAIL_ADDRESS";
  else if (type == 3)
    str_type = "IP_ADDRESS";
  else
    str_type = "UNKNOWN";
  return (str_type);
}

void	parserFile::myfork(std::string name, int cmd)
{
  pid_t m_pid = fork();

  if (m_pid == 0)
    {
      if (name != "exit")
	this->logfile << name << " " << intToCmdType(cmd) << " :" << std::endl;
      taskmanager(name, cmd);
      this->clientPipe();
    }
  else if (m_pid < 1)
    {
      std::cerr << RED << "Couldn't create a new process" << std::endl;
      kill(m_pid, SIGKILL);
    }
  this->serverPipe();
}

void	parserFile::printThreads()
{
  std::list<std::pair<listStr, int>>::const_iterator it;
  std::list<std::string>::const_iterator it2;

  this->logfile.open("log.txt", std::ios_base::app);
  if (mkfifo("/tmp/server_fifo", 0777) == -1)
    {
      perror("Mkfifo");
    }
  for (it = this->_command.begin(); it != this->_command.end(); ++it)
    {
      for (it2 = it->first.begin(); it2 != it->first.end(); ++it2)
	{
	  this->myfork(*it2, it->second);
	}
    }
  unlink("/tmp/server_fifo");
  this->logfile.close();
  collectedData.clear();
}
