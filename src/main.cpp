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

    COUT << "STORE DATA" << ENDL;
    store_data(board, solver_data);


    COUT << "INITIAL BOARD" << ENDL;
    display_initial_board(board);

    COUT << "SOLVING" << ENDL;
    path_solver(solver_data,sorted_path,start);

    COUT << "INITILIZING VECTOR" << ENDL;
    VECTOR<int>path (sorted_path.size(),0); //initialize path to have same size as stack, will need in main

    COUT << "CONVERTING VECTOR" << ENDL;
    convert_vect(sorted_path, path);

    COUT<<"Display solved table"<<ENDL;
	display_final_board(path,board);


    /* Return 0 if Successful */
    return 0;
}
