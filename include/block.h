/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: block.h
 * Date Created: 4/14/2022
 * File Contents: this file contains the function block struct for our b-cubed solver
 ************************************************/
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#define VECTOR std::vector
#define RIGHT     1<<0
#define LEFT      1<<1
#define UP        1<<2
#define DOWN      1<<3
#define NO_MOVES  1<<4

struct Block{
    public:
        int mode;               //int mode is for the type of block
        int flag;               //used to check movements of block
        int state;              //int state is for the active state of the block
        int x, y;               //these ints are for where to place block
        Block *next;            //points to next block in path, SLL for solver
        VECTOR<Block*> destins; //contains pointers to blocks that are possible moves
    
    //default constructor           for default blocks
    Block( x_in, y_in ):
        mode(1), state(1), x( x_in ), y( y_in ), next(NULL), destins(), flag(0){}
    
    //overload constructor          for special blocks
    Block(int mode_in, x_in, y_in):
        mode( mode_in ), state(1), x( x_in ), y( y_in ), next(NULL), destins(), flag(0) {}

    //Block functions
    
    // checks for possible movements around passed in block, and returns pointer to blocks
    // around the passed in block
    Block* check_block_moves(const Board& origin){
            //loop through SLL to check coordinates
            for(Block* next = board.origin; next; next->next){
                if(next->x == x+1 && !(RIGHT & flag)){
                    //set flag at curr block to say that the block has checked and has
                    //a block to the right so that it doesn't check again and keep in loop
                    flag |= RIGHT;
                    return next;
                }
                else if(next->x == x-1 && !(LEFT & flag)){
                    flag |= LEFT;
                    return next;
                }
                else if(next->y == y+1 && !(UP & flag)){
                    flag |= UP;
                    return next;
                }
                else if(next->y == y-1 && !(DOWN & flag)){
                    flag |= DOWN;
                    return next;
                }
            }
        
        //if board has gone through whole list and flag hasn't changed
        //set flag to say that there were no moves for this block
        if (curr->flag == 0)
            curr->flag |= NO_MOVES;
        return NULL;
    }
    
    /* Special Block functions
     * Jacob's section
     */
};

#endif
