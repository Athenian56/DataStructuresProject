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
#include <stack>
#include <fstream>
#include <stack>
#include "board.h"

#define UNOR_MAP std::unordered_map
#define STACK std::stack
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream
#define STACK std::stack
#define MAX_SIZE 16

//functions
void usage(int,char *progname);

void read_level(Board& board, IFSTREAM& input_file,long unsigned int& start);

//<<<<<<< HEAD
void key();
//=======
//>>>>>>> 0fbf8c3f3b997deeb78e1096a71b95d3d102554e

void display_initial_board(Board& board);

void display_final_board(VECTOR<int>&path, Board& board);

long unsigned int LinearSearch(VECTOR<int> &path, int x);

void convert_vect(STACK<int>&s, VECTOR<int>&path);

void store_data(Board& board, UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data);


void display_board(OFSTREAM& output);

void path_solver(UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data, STACK<int>& finalPath, long unsigned int& start);

#endif
