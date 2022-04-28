/************************************************
 * Names: Deep Brahmbhatt, Jacob Gutierrez, Jeriah Muleya, Delna Balsara
 * Emails: dbrahmbh@nd.edu, jgutier7@nd.edu, jmuleya@nd.edu, dbalsar1@nd.edu
 * File Name: bcubed.cpp
 * Date Created: 4/12/2022
 * File Contents: this file contains the function definitons for our b-cubed solver
 ************************************************/
#include "../include/bcubed.h"


/*void read_level(Board& board, IFSTREAM& input_file){
    
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

