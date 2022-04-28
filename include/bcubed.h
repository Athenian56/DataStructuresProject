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
#include <iomanip>
#include <unordered_map>
#include <cstdlib>
#include <fstream>
#include "board.h"

#define UNOR_MAP std::unordered_map
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream

//functions
void usage(int,char *progname);

void read_level(Board& board, IFSTREAM& input_file);

void key();

void display_initial_board(Board& board);

void display_final_board(VECTOR<int>&path, Board& board);

long unsigned int LinearSearch(VECTOR<int> &path, int x);

void store_data(Board& board, UNOR_MAP<int, VECTOR<int>>& solver_data);


//void display_board(OFSTREAM& output);

void path_solver();

#endif
