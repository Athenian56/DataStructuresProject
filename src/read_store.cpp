/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: read_store.cpp
 * Date Created: 4/14/2022
 * File Contents: this file contains the function definitons for read_in and store_data
 *                functions
 ************************************************/
#include "../include/bcubed.h"


void read_level(Board& board, IFSTREAM& input_file){
    
    
}

void store_data(Board& board, UNOR_MAP<int, VECTOR<int>>& solver_data){
    //pointer that will traverse board and store data into hash map
    for(Block* curr = board.origin; curr; curr = curr->next){
        //since down is last check of moves, check until down has ran, or no_moves
        //inputting for each block in board
        while((curr->flag & NO_MOVES) || (curr->flag & DOWN)){
            int temp = curr->check_block_moves(curr);
            if (temp != -1)
                curr->destins.push_back(temp);
        }
    }

    //store data into hash map for solver
    for(Block* curr = board.origin; curr; curr = curr->next){
        solver_data.insert({ curr->index, curr->destins });
    }

}
