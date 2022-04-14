/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: bcubed.h
 * Date Created: 4/12/2022
 * File Contents: this file contains the function declarations for our b-cubed solver
 ************************************************/

#ifndef BCUBED_H
#define BCUBED_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "board.h"

#define COUT std::cout
#define ENDL std::endl
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream

//functions
void read_level(, IFSTREAM& input_file);

void display_board(, OFSTREAM& output);

void path_solver();

#endif
