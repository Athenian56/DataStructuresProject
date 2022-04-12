/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: main.cpp
 * Date Created: 4/12/2022
 * File Contents: this file calls on our functions/structs and displays solution for given lvl
 ************************************************/
#include "../include/bcubed.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        COUT << "\nERROR: Incorrect Usage\n\n" << ENDL;
        COUT << argv[0] << " (level)\n\n" << ENDL;
        return 1;
    }

    return 0;
}
