/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: read_store.cpp
 * Date Created: 4/14/2022
 * File Contents: this file contains the function definitons for read_in and store_data
 *                functions
 ************************************************/
#include "../include/bcubed.h"


void read_level(, IFSTREAM& input_file){
    
}

void store_data(Board& board, UNOR_MAP<int, VECTOR<int>>& solver_data){
    //pointer that will traverse board and store data into hash map
    Block *curr = board.origin;
    //since down is last check of moves, check until down has ran, or no_moves
    while((curr->flags & NO_MOVES) || (curr->flags & DOWN)){
        curr->destins.pushback(check_block_moves);
    }
}
