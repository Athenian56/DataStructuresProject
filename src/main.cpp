/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: main.cpp
 * Date Created: 4/12/2022
 * Date Edited: 4/25/2022
 * File Contents: this file calls on our functions/structs and displays solution for given lvl
 ************************************************/
#include "../include/bcubed.h"

int main(int argc, char *argv[]){

    /* Ensure Correct Number of Command Line Inputs */
    if(argc != 2){  //sends to function telling user how to use main
        usage(argc,argv[0]); //tells the user that they ned more than one argument 
    } 

    /* Read Level Input */
	IFSTREAM bcubed_infile;
    long unsigned int start;
    Board board; //intilizes board
    bcubed_infile.open( argv[1] ); //opens the input
    read_level(board,bcubed_infile,start); //reads level



    /* Solve Puzzle */
    UNOR_MAP<long unsigned int, VECTOR<long unsigned int>> solver_data;
    STACK<int> sorted_path;
    // VECTOR<int>path (sorted_path.size(),0);//initialize path to have same size as stack, will need in main


    store_data(board, solver_data);


    COUT << "Initial board: " << ENDL;
    display_initial_board(board);


    path_solver(solver_data,sorted_path,start);


    VECTOR<int>path (sorted_path.size(),0); //initialize path to have same size as stack, will need in main

    // for (long unsigned int x = 0; x<sorted_path.size();x++){
    //     COUT << sorted_path.top() <<ENDL;
    //     sorted_path.pop();
    // }

    convert_vect(sorted_path, path);

    COUT<<"The final path is: "<<ENDL;
	display_final_board(path,board);



    // COUT << ENDL;
    // COUT << "Board inputs" << ENDL;
    // COUT << "( x  ,  y ),     mode,    index"<< ENDL;
    // for(Block* curr = board.origin; curr; curr = curr->next){
    //     COUT << "(" << std::setw(2) << curr->x << "  , " << std::setw(2) << curr->y << " ),    " << std::setw(3) << curr->mode << ",      " <<  std::setw(3) << curr->index<< ENDL;
    // }

    // COUT << ENDL;
	
	// //  COUT<<"Printing Data"<<ENDL;
	//  //display_board(board);
	// //  COUT<<ENDL;
    // /* DEBUGGING */ 
    // COUT << "hash table" << ENDL;
    // COUT << "Index\t\tDestins" << ENDL;
    // for(long unsigned int i = 0; i < solver_data.size(); i++){
    //     COUT << "  " << std::setw(2) << i << "\t\t";
    //     for(long unsigned int j = 0; j < solver_data[(int)i].size(); j++){
    //         if (j != 0)
    //             COUT << ", ";
    //         COUT << std::setw(2) << solver_data[(int)i][j];
    //     }
    //     COUT << ENDL;
    // }
    /* DEBUGGING */


    /* Return 0 if Successful */
    return 0;
}
