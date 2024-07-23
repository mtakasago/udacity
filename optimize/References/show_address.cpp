#include <iostream>
#include <vector>

using namespace std;

void matrix_address(vector< vector<int> > my_matrix)
{    
    cout << "function variable address: " << &my_matrix << "\n";
}

void matrix_address_ref(vector< vector<int> > &my_matrix)
{    
    cout << "referenced function variable address: " << &my_matrix << "\n";
}

int main()
{
    vector< vector<int> > matrix(5, vector<int>(6,2));
    cout << "original variable address: " << &matrix << "\n";
    matrix_address(matrix);
    matrix_address_ref(matrix);
    return 0;
}