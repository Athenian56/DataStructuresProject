/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: bcubed.cpp
 * Date Created: 4/12/2022
 * Date Edited: 4/25/2022
 * File Contents: this file contains the function definitons for our b-cubed solver
 ************************************************/
#include "../include/bcubed.h"
#define MAX_SIZE 16
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

void read_level(Board& board, IFSTREAM& input_file){
    char temp;
    int index = 0, x=0, y=5, mode = 1;
    

    //want to loop through one character at a time
//<<<<<<< HEAD
    while(input_file >> temp){
        bool increase = true;
//=======
 //   while(input_file >> temp){ 
//>>>>>>> 7663d20a84669818ce34d92330d2ba82fb07a3db
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
                //increase = false;
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
//=======

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
//>>>>>>> 0fbf8c3f3b997deeb78e1096a71b95d3d102554e


void store_data(Board& board, UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data){
    //pointer that will traverse board and store data into hash map
    for(Block* curr = board.origin; curr; curr = curr->next){
        //since down is last check of moves, check until down has ran, or no_moves
        //inputting for each block in board
        while(!((curr->flag & NO_MOVES) == NO_MOVES) || !((curr->flag & DOWN) == DOWN)){
            int temp = (int)curr->check_block_moves(board.origin);
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
	for(long signed int i=vec.size()-1;i>-1;i--){
		
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

	VECTOR<char> vect(MAX_SIZE,' ');
	VECTOR<VECTOR<char>> display (MAX_SIZE, vect);//create display of 0s.

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



/*
// reads board from input file 
void read_level(Board& board, IFSTREAM& input_file){
    
} // 


void store_data(Board& board, UNOR_MAP<int, VECTOR<int>>& solver_data){

} 

//create seperate files that contain the include statement so we can all work on different 
//parts

//delna
void display_board(){

}
*/

//deep
//private topological sorting algorithm to check single index using hashmap of a (index, indices of possible blocks)
void index_check(long unsigned int index, UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data, VECTOR<int>& parents, VECTOR<bool>& visited)
{
	long unsigned int iter;
	
	if ( !visited[ index ] )
	{
		//set visited index to true
		visited [ index ] = true;
		
		//check each possible block
		for ( iter = 0; iter < solver_data[index].size(); iter++ )
		{
			//if index of possible block has not been visited, resursive call is made
			if ( !visited[ solver_data[ index ][ iter ] ] )
			{
				//set the possible block's parent as the current index
				parents[ solver_data[ index ][ iter ] ] = (int)index;

				//recursive call meant to run through the possible blocks of the current possible block and so on
				index_check( solver_data[ index ][ iter ], solver_data, parents, visited );
				//check if parents contains only 1 -1, if so return(found path) if not set current index's parent back to negative one and loop
				//back up to that
			}
		}
	}

	/*unsigned int iter;
	VECTOR<int> path_indices();
	VECTOR<bool> visited_indices(solver_data.size(), false);
	VECTOR<int> visited_possible_blocks;

	visited_indices[0] = true;

	//assures all indices are included in path
	while (path_indices.size() != solver_data.size())
	{
		//set the visited indices to true
		if (! (visited_indices[solver_data[v]->second[iter]]))
		{
			visited_indices[solver_data[v]->second[iter]] = true;

			//check each possble block (edge)


		}
	}

		for (iter = 0; iter < solver_data[v])
*/
	
}

STACK<int> path_solver(UNOR_MAP<long unsigned int, VECTOR<long unsigned int>>& solver_data)
{
	STACK<int> finalPath;

	VECTOR<int> parents(solver_data.size());

	VECTOR<bool> visited(solver_data.size());
	
	long unsigned int iter, sentinel = (solver_data.size()-1);

	//set all of the visited elements to false
	for( iter = 0; iter < solver_data.size(); iter++ )
	{
		visited[iter] = false;
		parents[iter] = -1;
	}
	
	//run the topsort for every index
	for(iter = 0; iter < solver_data.size(); iter++ )
	{
		index_check( iter, solver_data, parents, visited );
	}
	
	finalPath.push( (int)sentinel );

	while ( parents[sentinel] != -1 )
	{
		finalPath.push( parents[sentinel] );
		sentinel = parents[sentinel];
	}

	return finalPath;
}

