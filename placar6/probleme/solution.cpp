#include <iostream>

using namespace std;

int main () {
    int t = 0;

    cin >> t;

    for (int i = 0; i < t; i++) {
        long long a;
        cin >> a;
        long long b;
        cin >> b;

        int r = a % b;

        if (r == 0) {
            cout << r << "\n";
        } else {
            r = b - r; 
            cout << r << "\n";
        }
    }

}