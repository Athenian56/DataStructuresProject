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
    Board board; //intilizes board
    bcubed_infile.open( argv[1] ); //opens the input
    read_level(board,bcubed_infile); //reads level

    /* Solve Puzzle */
    UNOR_MAP<long unsigned int, VECTOR<long unsigned int>> solver_data;
    store_data(board, solver_data);
	
	 COUT<<"Printing Data"<<ENDL;
	 //display_board(board);
	 COUT<<ENDL;
    /* DEBUGGING */ 
    COUT << "hash table" << ENDL;
    COUT << "Index\t\tDestins" << ENDL;
    for(long unsigned int i = 0; i < solver_data.size(); i++){
        COUT << "  " << std::setw(2) << i << "\t\t";
        for(long unsigned int j = 0; j < solver_data[(int)i].size(); j++){
            if (j != 0)
                COUT << ", ";
            COUT << std::setw(2) << solver_data[(int)i][j];
        }
        COUT << ENDL;
    }
    /* DEBUGGING */


    /* Return 0 if Successful */
    return 0;
}
