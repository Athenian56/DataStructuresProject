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
#define COUT std::cout
#define ENDL std::endl
#define RIGHT     1<<0
#define LEFT      1<<1
#define UP        1<<2
#define DOWN      1<<3
#define NO_MOVES  1<<4

struct Block{
    public:
        int mode;               //int mode is for the type of block
        int flag;               //used to check movements of block
        int index;              
        int state;              //int state is for the active state of the block
        int x, y;               //these ints are for where to place block
        Block *next;            //points to next block in path, SLL for solver
        VECTOR<int> destins; //contains pointers to blocks that are possible moves
    
    //default constructor           for default blocks
    Block(int x_in, int y_in ):
        mode(1), flag(0), index(), state(1), x( x_in ), y( y_in ), next(NULL), destins() {}
    
    //overload constructor          for special blocks
    Block(int mode_in,int x_in, int y_in, int index_in):
        mode( mode_in ), flag(0), index(index_in), state(1), x( x_in ), y( y_in ), next(NULL), destins() {}

    //Block functions
    
    // checks for possible movements around passed in block, and returns index of block
    // around the passed in block
    int check_block_moves(Block*& board){
        //loop through SLL to check coordinates
        for(Block* iter = board; iter; iter = iter->next){
            if((iter->x == x+1 && iter->y == y) && !((RIGHT & flag) == RIGHT)){
                //set flag at curr block to say that the block has checked and has
                //a block to the right so that it doesn't check again and keep in loop
                flag |= RIGHT;
                //COUT << index << "Hit right" << next->index << ENDL;
                return iter->index;
            }
            else if((iter->x == x-1 && iter->y == y) && !((LEFT & flag) == LEFT)){
                flag |= LEFT;
                //COUT << "Hit left" << ENDL;
                return iter->index;
            }
            else if((iter->y == y+1 && iter->x == x) && !((UP & flag) == UP)){
                flag |= UP;
                //COUT << "Hit up" << ENDL;
                return iter->index;
            }
            else if((iter->y == y-1 && iter->x == x) && !((DOWN & flag) == DOWN)){
                flag |= DOWN;
                //COUT << "Hit down" << ENDL;
                return iter->index;
            }
        }
        
        //if board has gone through whole list and flag hasn't changed
        //set flag to say that there were no moves for this block
        if (flag == 0)
            flag |= NO_MOVES;
        return -1;
    }
    
    /* Special Block functions
     * Jacob's section
     * Will do when we figure get test case working 
     */

    /*

    //function to acitvate other blocks when a secial block is landed on, will be called in solving algorithm 
    int activate_special(){

    }


    */

    

};

#endif
