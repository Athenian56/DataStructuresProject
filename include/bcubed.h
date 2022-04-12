/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: bcubed.h
 * Date Created: 4/12/2022
 * File Contents: this file contains the function declarations and structs for our b-cubed 
 *                solver
 ************************************************/

#ifndef BCUBED_H
#define BCUBED_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

#define COUT std::cout
#define VECTOR std::vector
#define ENDL std::endl
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream

//structs

struct Block{
    public:
        int mode;               //int mode is for the type of block
        int state;              //int state is for the active state of the block
        int x, y;               //these ints are for where to place block
    
    //default constructor           for default blocks
    Block( x_in, y_in ):
        mode(1), state(1), x( x_in ), y( y_in ){}
    
    //overload constructor          for special blocks
    Block(int mode_in, x_in, y_in):
        mode( mode_in ), state(1), x( x_in ), y( y_in ) {}
};

//functions
void read_level(, IFSTREAM& input_file);

void display_board();

void path_solver();

#endif
