#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector<vector<float>> initialize_beliefs(vector< vector <char> > &grid) {

  	vector<vector<float>> newGrid;
  	newGrid.reserve(grid.size());
	// OPTIMIZATION: Which of these variables are necessary?
	// OPTIMIZATION: Reserve space in memory for vectors
	vector<float> newRow(grid[0].size(),1.0/(grid.size() * grid[0].size()));
  	// OPTIMIZATION: Is there a way to get the same results 	// without nested for loops?
	for (int i=0; i<grid.size(); i++) newGrid.push_back(newRow);
	return newGrid;
}