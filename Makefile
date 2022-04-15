# Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
# File Name: bcubed.h
# Date Created: 4/12/2022
# File Contents: this is the Makefile for our b-cubed solver

# Compiler Variables
CC := g++
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 $(FLAGS)

# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# File Variables
MAIN := main
FUNC := bcubed

# Make initialize
initialize:
	@echo Initializing...
	@rm -rf $(OBJ) $(EXE)
	@mkdir $(OBJ) $(EXE)

# Make Final Project
$(OBJ)/$(FUNC).o: $(SRC)/$(FUNC).cpp
	@echo Linking stuff...
	$(CC) $(CXXFLAGS) -c $(SRC)/$(FUNC).cpp -o $@

$(OBJ)/$(MAIN).o: $(SRC)/$(MAIN).cpp
	@echo Linking project...
	@$(CC) $(CXXFLAGS) -c $(SRC)/$(MAIN).cpp -o $@

ProjectObjs := $(OBJ)/$(FUNC).o $(OBJ)/$(MAIN).o

Project: $(ProjectObjs)
	@echo Compiling executable...
	@$(CC) $(CXXFLAGS) -o $(EXE)/$(MAIN) $(ProjectObjs)

# Make clean
clean:
	@echo Cleaning...
	@rm -rf $(OBJ)/* $(EXE)/*
