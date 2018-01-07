##
## Makefile for  in /home/hazer/plazza
## 
## Made by hazer
## Login   <hazer@epitech.net>
## 
## Started on  Tue Apr 11 10:50:18 2017 hazer
## Last update Wed Apr 26 14:00:17 2017 hazer
##

TARGET	 = plazza

CC	 = g++

SRC      = main.cpp		\
	   parserCmd.cpp	\
	   plazza.cpp		\
	   stringFunc.cpp	\
	   parserFile.cpp	\
	   decrypt.cpp		\
	   task.cpp		\

CFLAGS   += -W -Wall -ansi -pedantic -Iinclude -std=c++11 -g

LDFLAGS	 += -lpthread

SRCDIR	 = src
OBJDIR	 = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(CFLAGS) $(LDFLAGS)
	@echo $(TARGET)" compiled !"
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all     : $(TARGET)

clean   :
	@$(rm) $(OBJDIR)
	@echo "Binary files deleted"

fclean  : clean
	@$(rm) $(TARGET) $(LINK)
	@echo "Binary and executable files are deleted"

re      : fclean all

.PHONY: all clean fclean re
