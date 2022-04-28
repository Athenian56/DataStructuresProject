/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: bcubed.cpp
 * Date Created: 4/12/2022
 * Date Edited: 4/25/2022
 * File Contents: this file contains the function definitons for our b-cubed solver
 ************************************************/
#include "../include/bcubed.h"
// usage function
void usage(int argc,char *progname) {
    if(argc==1) {
        std::cerr << "ERROR: Too few arguments" << ENDL;
    } else {
        std::cerr << "ERROR: Too many arguments" << ENDL;
    }
     std::cerr << "Usage: B-CUBED SOLVER requires two arguments:"  << ENDL << 
     "                    * executable " << ENDL <<
     "                    * a text file containing the data for the level." << ENDL << ENDL <<
     "         " << progname << " [level].txt" << ENDL << ENDL;
     exit(1);
}

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

void display_board(Board& board){
	for(Block* curr=board.origin; curr;curr=curr->next){
		if(curr->state==1){
			std::cout<<"X";
		}
		else{
			std::cout<<"0";
		}
	}
}

void store_data(Board& board, UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data){
    //pointer that will traverse board and store data into hash map
    for(Block* curr = board.origin; curr; curr = curr->next){
        //since down is last check of moves, check until down has ran, or no_moves
	if(curr->mode == 2)
		continue;
        //inputting for each block in board
		if(curr->mode==2){
			continue;
		}
        while(!((curr->flag & NO_MOVES) == NO_MOVES) || !((curr->flag & DOWN) == DOWN)){
            int temp = (int)curr->check_block_moves(board.origin);
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

void key(){
	COUT<<"Key for initial board display"<<ENDL;
	COUT<<"X: regular cube"<<ENDL;
	COUT<<"S: starting cube"<<ENDL;
	COUT<<"E: ending cube"<<ENDL;
	COUT<<"x: needs to be activated"<<ENDL;
	COUT<<"2: can be used twice"<<ENDL;
	COUT<<"-: bridge"<<ENDL;

}

void convert_vect(STACK<int>&s,VECTOR<int>&vec){//converts stack to vector
	for(long unsigned int i=0;i<vec.size();i++){		
		vec[i]=s.top();
		s.pop();
	}
	COUT<<ENDL;
	
}


void display_initial_board(Board& board){

	VECTOR<char> vect(MAX_SIZE,' ');
	VECTOR<VECTOR<char>> display (MAX_SIZE, vect);//create display of 0s.
		
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
	VECTOR<long unsigned int> vect(MAX_SIZE,999);
	VECTOR<VECTOR<long unsigned int>> display (MAX_SIZE, vect);//create display of 0s.
	COUT<<"BOARD:"<<ENDL;
		for(Block* curr=board.origin;curr;curr=curr->next){//loop through blocks, set space on the board with the block's index
			display[curr->y][curr->x]=(curr->index);
		}
		
		long unsigned int temp;
		int x;//to be searched
		for(long signed int i=MAX_SIZE-1;i>-1;i--){
			for(long signed int j=0;j<MAX_SIZE;j++){
				if(display[i][j]!=999){//if index, search path for the index, and display index 
					x=(int)display[i][j];
					temp=LinearSearch(path, x);
					if(temp==0){
						COUT<<std::setw(3)<<"S";
					}	
					else if(temp==999)
						COUT<<std::setw(3)<<"E";
					else
						COUT <<std::setw(3)<< temp;
				}
				if(display[i][j]==999){
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
 	return 999;
 }

//private topological sorting algorithm to check single index using hashmap of a (index, indices of possible blocks)
void index_check(long unsigned int index, UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data, VECTOR<int>& parents, VECTOR<bool>& visited)
{
	long unsigned int count = 0;
	
	if ( !visited[ index ] )
	{
		//set visited index to true
		visited [ index ] = true;
		
		//check each possible block
		for ( long unsigned int iter = 0; iter < solver_data[index].size(); iter++ )
		{
			//if index of possible block has not been visited, resursive call is made
			if ( !visited[ solver_data[ index ][ iter ] ] )
			{
				//set the possible block's parent as the current index
				parents[ solver_data[ index ][ iter ] ] = (int)index;
				if(count==1)return;
				for(long unsigned int jter = 0; jter < parents.size(); jter++){
					 if(parents[jter] == -1){
						count++;
					 }
				}

				//recursive call meant to run through the possible blocks of the current possible block and so on
				//if(solver_data.size() == 0 )
				index_check( solver_data[ index ][ iter ], solver_data, parents, visited);
				//COUT << "RETURNING" << ENDL;

			}
		}
	}
	
}

void path_solver(UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data, STACK<int>& finalPath, long unsigned int& start)
{
	//STACK<int> finalPath;
	//long unsigned int count = 0;

	VECTOR<int> parents(solver_data.size(), -1);

	VECTOR<bool> visited(solver_data.size(), false);
	
	long unsigned int sentinel = (solver_data.size()-1);

		index_check(start,solver_data,parents,visited);

	finalPath.push( (int)sentinel );

	while ( parents[sentinel] != -1 )
	{
		finalPath.push( parents[sentinel] );
		sentinel = parents[sentinel];
	}

	return;
}

