#include "scalar_multiply_improved.hpp"
using namespace std;

vector< vector<int> > scalar_multiply_improved(vector< vector<int> > matrix, int scalar) {
    
  	// OPTIMIZATION: Instead of creating a new variable
    // called resultmatrix, update the input matrix directly
//     vector< vector<int> > resultmatrix;
    vector<int> new_row(matrix[0].size());
    
//     vector<int>::size_type num_rows = matrix.size();
//     vector<int>::size_type num_cols = matrix[0].size();
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            new_row[j] = matrix[i][j] * scalar;
        }
        matrix[i] = new_row;
    }
    
    return matrix;
}
