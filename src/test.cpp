#include "../include/bcubed.h"
int main(int argc, char* argv[]){
        if(argc != 2){
            COUT << "Usage: " << argv[0] << " InputFile" << ENDL;
            return 1;
        }

    Board board;
    IFSTREAM file_name(argv[1]);
    read_level(board, file_name);
    
    COUT << ENDL;
    COUT << "Board inputs" << ENDL;
    COUT << "( x  ,  y ),     mode,    index"<< ENDL;
    for(Block* curr = board.origin; curr; curr = curr->next){
        COUT << "(" << std::setw(2) << curr->x << "  , " << std::setw(2) << curr->y << " ),    " << std::setw(3) << curr->mode << ",      " <<  std::setw(3) << curr->index<< ENDL;
    }

    COUT << ENDL;
    UNOR_MAP<int, VECTOR<int>> solver_data;

	 key();
	 COUT<<ENDL;
	
    COUT<<"Display initial board"<<ENDL;
	 display_initial_board(board);

	 STACK<int> test_stack;//initialize stack, will not need in main
	 for(int i=0;i<25;i++){
		 test_stack.push(i);
	 }
	
	 COUT<<ENDL;

	 VECTOR<int>test_path (test_stack.size(),0);//initialize path to have same size as stack, will need in main

	 convert_vect(test_stack, test_path);

	 COUT<<"Display solved table"<<ENDL;
	 display_final_board(test_path,board);

    store_data(board, solver_data);
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


    return 0;
}
