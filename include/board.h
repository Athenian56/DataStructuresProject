/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: board.h
 * Date Created: 4/14/2022
 * File Contents: this file contains the board struct for our b-cubed solver
 ************************************************/
#ifndef BOARD_H
#define BOARD_H

#include "block.h"

struct Board{
    
    private:
        
            void destructor (Block* curr_block){
                if (curr_block==NULL)
                    return;

                destructor(curr_block->next);

                delete curr_block;
            }

    //SLL????
    public: 
        Block* origin;            //put origin here, use to traverse SLL                 

        //default Constructor
        Board(): origin(NULL) {}

        //destructor
        ~Board(){
            destructor(this->origin);
        }

        //board functions

        void push( const int& x, const int& y, const int& mode, const int& index){
            Block* temp_block = new Block( mode, x, y, index);
            // Dr. Morrison's golden rule of pointers
            if (this->origin == NULL){
                this->origin = temp_block;

                return;
            }
            // if not new, cycle through SLL until next is null
            for(Block* curr= origin;curr;curr = curr->next){
                    if(curr->next == NULL){
                        curr->next = temp_block;
                        return;
                    }
            }
            
        }

        //pop from top of SLL
        void pop_front(){
            //remove front item from stack and set new origin
            Block* new_origin = origin->next;
            delete origin;
            origin = new_origin;
        }
};

#endif
