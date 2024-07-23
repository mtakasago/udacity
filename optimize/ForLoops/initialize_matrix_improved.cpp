#include "initialize_matrix_improved.hpp"

using namespace std;
vector < vector<int> > initialize_matrix_improved(int num_rows, int num_cols, int initial_value) {
    
    vector < vector<int> > matrix;
    vector<int> new_row(num_cols,initial_value);
    
    for (int i = 0; i < num_rows; i++) matrix.push_back(new_row);
    
    return matrix;
}
