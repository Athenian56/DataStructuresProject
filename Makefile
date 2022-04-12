# Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
# File Name: bcubed.h
# Date Created: 4/12/2022
# File Contents: this is the Makefile for our b-cubed solver

# Compiler Variables
CC := g++
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -lm
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
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# Make Final Project
$(OBJ)/$(FUNC).o: $(SRC)/$(FUNC).cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/$(FUNC).cpp -o $@

$(OBJ)/$(MAIN).o: $(SRC)/$(MAIN).cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/$(MAIN).cpp -o $@

MainObjs := $(OBJ)/$(FUNC).o $(OBJ)/$(MAIN).o

Main := $(initialize) $(MainObjs)
	$(CC) $(CXXFLAGS) -o $(EXE)/$(MAIN) $(MainObjs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
