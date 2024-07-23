#include <iostream>
#include <ctime>

using namespace std;
int main(int argc, const char * argv[]) {
    
    std::clock_t start;
    double duration_one, duration_two;
    start = std::clock();

    for (int i = 0; i < 100000; i++) {
        if (i > 0 && i < 5) {
            cout <<  "low \n";
        }
        else if (i <= 10) {
            cout << "low-medium \n";
        }
        else if (i <= 35) {
            cout << "medium \n";
        }
        else if (i <= 37) {
            
            cout << "medium-high \n";
        }
//         if (i > 37) {
        else {
            cout << "high \n";
        }
    }

    duration_one = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::clock_t start2;
    start2 = std::clock();

  	// optimize the if statements below
    for (int i = 0; i < 100000; i++)
    {
        if (i > 37) cout <<  "high \n";
        else if (i > 35) cout << "medium-high \n";
        else if (i > 10) cout << "medium \n";
        else if (i >= 5) cout << "medium-low \n";
        else cout << "low \n";
    }
    duration_two = ( std::clock() - start2 ) / (double) CLOCKS_PER_SEC;

    cout << "duration milliseconds not optimized: " << 1000 * duration_one << '\n';

    cout << "duration milliseconds optimized: " << 1000 * duration_two << '\n';

    return 0;
}
