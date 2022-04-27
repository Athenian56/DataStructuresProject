/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: read_store.cpp
 * Date Created: 4/14/2022
 * Date Edited: 4/25/2022
 * File Contents: this file contains the function definitons for read_in and store_data
 *                functions
 ************************************************/
#include "../include/bcubed.h"


void read_level(Board& board, IFSTREAM& input_file){
    char temp;
    int index = 0, x=0, y=5, mode = 1;
   // VECTOR<int> rows_count;
	 //int cols=0;
	
    //want to loop through one character at a time
    while(input_file >> temp){
        bool increase = true;
        switch(temp){
            case '1':               //normal block
                mode = 1;
                break;

            case 'S':               //starting block
                mode = -1;
                break;

            case 'E':               //final block
                mode = 2;
                break;
                
            case '0':               //inactive / no block
                x++;                // skips position
                increase = false;
                break;

            case 'N': //end of a line on the board 
                y--;
					 //cols++;
                x=0;
                increase = false;
                break;
            
            /* special block cases */
            case 'T': //block that can be used twice
                mode = 3;
                break;

            case 'B': //block that activates a bridge between two other blocks
                /* input a vector of coordinates that the block would activate */
                mode = 3;
                break;
            
            case 'b':
                mode = -2; //block that's not acitvated yet
                break;

        }
        //if character is a read in, then delcare new block and push to board
        if(increase){ 
            //Block* load_block = new Block(mode, x, y, index);
            board.push(x, y, mode, index);
            index++;
            x++;
        }
            
    }
}

void display_initial_board(Board& board){
	Block* curr=board.origin;
	//for(long unsigned int i=0;i<board.size();i++){
		//for(long unsigned int j=0;j<board[i].size();j++){
		
		for(Block* curr=board.origin;curr;curr=curr->next){
			if(curr->mode==1){//regular block
				std::cout<<"X";
			}
			else if(curr->mode==-1){//starting block
				std::cout<<"S";
			}
			else if(curr->mode==2){//final block
				std::cout<<"E";
			}
			else if(curr->mode==-2){//needs to be activated
				std::cout<<"x";
			}
			else if(curr->mode==3){
				std::cout<<"2";
			}
			else{
				std::cout<<"0";
			}
			//curr=curr->next;
		}
		//}
		COUT<<ENDL;
	//}

}

void store_data(Board& board, UNOR_MAP<int, VECTOR<int>>& solver_data){
    //pointer that will traverse board and store data into hash map
    for(Block* curr = board.origin; curr; curr = curr->next){
        //since down is last check of moves, check until down has ran, or no_moves
        //inputting for each block in board
        while(!((curr->flag & NO_MOVES) == NO_MOVES) || !((curr->flag & DOWN) == DOWN)){
            int temp = curr->check_block_moves(board.origin);
            if (temp != -1)
                curr->destins.push_back(temp);
            else
                break;
        }
    }

    //store data into hash map for solver
    for(Block* curr = board.origin; curr; curr = curr->next){
        solver_data.insert({ curr->index, curr->destins });
    }

}
