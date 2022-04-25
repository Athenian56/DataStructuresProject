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

//deep
void path_solver(){

} 
// */

