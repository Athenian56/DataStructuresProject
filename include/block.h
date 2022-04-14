/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: block.h
 * Date Created: 4/14/2022
 * File Contents: this file contains the function block struct for our b-cubed solver
 ************************************************/
#ifndef BLOCK_H
#define BLOCK_H

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

#endif
