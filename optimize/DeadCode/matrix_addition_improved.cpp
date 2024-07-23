#include "matrix_addition_improved.h"

using namespace std;

vector < vector <int> > matrix_addition_improved (vector < vector <int> > matrixa, vector < vector <int> > matrixb) {
    
    // store the number of rows and columns in the matrices
//     vector<int>::size_type rows_a = matrixa.size();
//     vector<int>::size_type rows_b = matrixb.size();
//     vector<int>::size_type cols_a = matrixa[0].size();
//     vector<int>::size_type cols_b = matrixb[0].size();

    // default zero vector
    vector <vector <int> > sum_vector(matrixa.size(),vector<int>(matrixa[0].size()));

    // if both matrices have the same size, calculate and return the sum
    // otherwise check if the number of rows and columns are not equal and return a matrix of zero
    if (matrixa.size() == matrixb.size() && matrixa[0].size() == matrixb[0].size()) {
         
        for (unsigned int i = 0; i < matrixa.size(); i++) {//
            for (unsigned int j = 0; j <matrixa[0].size(); j++) {
                sum_vector[i][j] = matrixa[i][j] + matrixb[i][j];
            }
        }
    }
    return sum_vector;
    
}
