#include "headers/blur.h"
#include "headers/zeros.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	// OPTIMIZATION: window, DX and  DY variables have the 
    // same value each time the function is run.
  	// It's very inefficient to recalculate the vectors
    // every time the function runs. 
    // 
    // The const and/or static operator could be useful.
  	// Define and declare window, DX, and DY using the
    // bracket syntax: vector<int> foo = {1, 2, 3, 4} 
    // instead of calculating these vectors with for loops 
    // and push back
	int height = grid.size();
	int width = grid[0].size();
  	vector < vector <float> > newGrid = zeros(height,width);
   // calculate blur factors
    static float center = 1.0 - blurring;
    static float corner = blurring / 12.0;
    static float adjacent = blurring / 6.0;
    // create the blur window
    static vector< vector<float> > window = {{corner, adjacent, corner}, {adjacent, center, adjacent}, {corner, adjacent, corner}};

  	int i, j, dx, dy;
	int new_i, new_j;
	float multiplier;
	float newVal;

	// OPTIMIZATION: Use your improved zeros function

	for (i=0; i< height; i++ ) {
		for (j=0; j<width; j++ ) {
			newVal = grid[i][j];
			for (dx=-1; dx<2; dx++) {
				for (dy=-1; dy<2; dy++) {
					new_i = (i + dx + height) % height;
					new_j = (j + dy + width) % width;
					multiplier = window[dx+1][dy+1];
					newGrid[new_i][new_j] += newVal * multiplier;
				}
			}
		}
	}

	return newGrid;
}
