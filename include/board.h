/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: board.h
 * Date Created: 4/14/2022
 * File Contents: this file contains the board struct for our b-cubed solver
 ************************************************/
#ifndef BOARD_H
#define BOARD_H

#include "block.h"

#define 

struct Board{

    public: 
        Block* origin;            //put origin here, use to traverse SLL                     

    //default Constructor
    Board(): curr_Block(NULL) {}

    //board functions
  
    // checks for possible movements around passed in block, and returns pointer to blocks
    // around the passed in block
    Block* check_block_moves(Block *curr){
            //loop through SLL to check coordinates
            for(Block* next = origin; next; next->next){
                if(next->x == curr->x+1 && !(RIGHT & curr->flag)){
                    //set flag at curr block to say that the block has checked and has
                    //a block to the right so that it doesn't check again and keep in loop
                    curr->flag |= RIGHT;
                    return next;
                }
                else if(next->x == curr->x-1 && !(LEFT & curr->flag)){
                    curr->flag |= LEFT;
                    return next;
                }
                else if(next->y == curr->y+1 && !(UP & curr->flag)){
                    curr->flag |= UP;
                    return next;
                }
                else if(next->y == curr->y-1 && !(DOWN & curr->flag)){
                    curr->flag |= DOWN;
                    return next;
                }
            }
        
        //if board has gone through whole list and flag hasn't changed
        //set flag to say that there were no moves for this block
        if (curr->flag == 0)
            curr->flag |= NO_MOVES;
        return NULL;
    }

};

#endif
