#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n = 0;

    cin >> n;

    int test = n % 4;

    if (n == 0) {
        cout << "1" << endl;

    } else if (test == 0){
        cout << "6" << endl;

    } else if (test == 1) {
        cout << "8" << endl;
    
    } else if (test == 2) {
        cout << "4" << endl;

    } else if (test == 3) {
        cout << "2" << endl;

    }
}

