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

#define MAX_SIZE 16

void read_level(Board& board, IFSTREAM& input_file, long unsigned int& start){
    char temp;
    int index = 0, x=0, y=5, mode = 1;
	
    //want to loop through one character at a time
    while(input_file >> temp){
        bool increase = true;
        switch(temp){
            case '1':               //normal block
                mode = 1;
                break;

            case 'S':               //starting block
                mode = -1;
				start = index;
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
                x=0;
                increase = false;
                break;
            
            /* special block cases */
            case 'T': //block that can be used twice
                mode = 3;
                break;

            case 'B': //block that activates a bridge between two other blocks
                /* input a vector of coordinates that the block would activate */
                mode = 4;
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

//<<<<<<< HEAD
void key(){
	COUT<<"Key for initial board display"<<ENDL;
	COUT<<"X: regular cube"<<ENDL;
	COUT<<"S: starting cube"<<ENDL;
	COUT<<"E: ending cube"<<ENDL;
	COUT<<"x: needs to be activated"<<ENDL;
	COUT<<"2: can be used twice"<<ENDL;
	COUT<<"-: bridge"<<ENDL;

}
//=======
//>>>>>>> 0fbf8c3f3b997deeb78e1096a71b95d3d102554e

void display_initial_board(Board& board){

	VECTOR<char> vect(MAX_SIZE,' ');
	VECTOR<VECTOR <char> > display (MAX_SIZE, vect);//create display of 0s.
		
	for(Block* curr=board.origin;curr;curr=curr->next){//loop through blocks, and change value at display based on mode at the coordinates
		if(curr->mode==1){//regular block
			display[curr->y][curr->x]='X';
		}
		else if(curr->mode==-1){//starting block
			display[curr->y][curr->x]='S';
		}
		else if(curr->mode==2){//final block
			display[curr->y][curr->x]='E';
		}
		else if(curr->mode==-2){//needs to be activated
			display[curr->y][curr->x]='x';
		}
		else if(curr->mode==3){//can be used twice
			display[curr->y][curr->x]='2';
		}
		else if(curr->mode==4){//bridge
			display[curr->y][curr->x]='-';
		}
		else{
			display[curr->y][curr->x]=0;
		}
	}

	
	for(long signed int i=MAX_SIZE-1;i>-1;i--){
		for(long signed int j=0;j<MAX_SIZE;j++){
			COUT<<display[i][j]<<" ";
		}
		COUT<<ENDL;
	}
	COUT<<ENDL;
	

}

void display_final_board(VECTOR<int>&path, Board& board){
//loop through vector of ints

	VECTOR<char> vect(MAX_SIZE,' ');
	VECTOR<VECTOR<char> > display (MAX_SIZE, vect);//create display of 0s.

		for(Block* curr=board.origin;curr;curr=curr->next){//loop through blocks, set space on the board with the block's index
			display[curr->y][curr->x]=(char)(curr->index);
		}
		
		
		long signed int temp;
		int x;//to be searched
		for(long signed int i=MAX_SIZE-1;i>-1;i--){
			for(long signed int j=0;j<MAX_SIZE;j++){
				if(display[i][j]!=' '){//if index, search path for the index, and display index 
					x=(int)display[i][j];
					temp=LinearSearch(path, x);	
					COUT <<std::setw(3)<< temp;
				}
				
				if(display[i][j]==' '){
					COUT <<std::setw(3)<<" ";
				}
			}
			COUT<<ENDL;
		}
		COUT<<ENDL;

}

long unsigned int LinearSearch(VECTOR<int> &path,int x){
	for(long unsigned int i=0;i<path.size();i++){
		if(path[i]==x){
			return i;
		}
	}	
	return -1;
}

void convert_vect(STACK<int>&s,VECTOR<int>&vec){//converts stack to vector
	for(long signed int i=vec.size()-1;i>-1;i--){
		
		vec[i]=s.top();
		s.pop();
	}
	COUT<<ENDL;
	
}

void store_data(Board& board, UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data){    
    //pointer that will traverse board and store data into hash map
    for(Block* curr = board.origin; curr; curr = curr->next){
        //since down is last check of moves, check until down has ran, or no_moves
        //inputting for each block in board
		if(curr->mode==2){
			continue;
		}
        while(!((curr->flag & NO_MOVES) == NO_MOVES) || !((curr->flag & DOWN) == DOWN)){
            long unsigned int temp = curr->check_block_moves(board.origin);
            if (temp != 999999)
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
