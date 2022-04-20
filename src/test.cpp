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
    COUT << "(x, y),  mode,  index"<< ENDL;
    for(Block* curr = board.origin; curr; curr = curr->next){
        COUT << "(" << curr->x << ", " << curr->y << "),    " << curr->mode << ",      " << curr->index<< ENDL;
    }

    COUT << ENDL;
    UNOR_MAP<int, VECTOR<int>> solver_data;

    store_data(board, solver_data);
    COUT << "hash table" << ENDL;
    COUT << "Index\t\tDestins" << ENDL;
    for(long unsigned int i = 0; i < solver_data.size(); i++){
        COUT << "  " << i << "\t\t";
        for(long unsigned int j = 0; j < solver_data[(int)i].size(); j++){
            if (j != 0)
                COUT << ", ";
            COUT << solver_data[(int)i][j];
        }
        COUT << ENDL;
    }


    return 0;
}
