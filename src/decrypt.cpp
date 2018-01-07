//
// decrypt.cpp for  in /home/hazer/cpp_plazza/src
//
// Made by hazer
// Login   <hazer@epitech.net>
//
// Started on  Mon Apr 24 17:07:57 2017 hazer
// Last update Tue Apr 25 18:11:27 2017 hazer
//

#include <fstream>
#include <string>
#include <iostream>

std::string	decryptCaesar(std::string src, unsigned short key)
{
  std::string decrypted(src);
  unsigned int   i;

  for (i = 0; i < src.length(); i++)
    decrypted[i] -= key;
  return (decrypted);
}

std::string	decryptXor(std::string line, unsigned short key)
{
  std::string output(line);
  unsigned int   i;

  for (i = 0; i < line.size(); i++)
    output[i] = line[i] ^ key;
  return (output);
}
