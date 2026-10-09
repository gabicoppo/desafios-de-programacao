#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    int c = 0;

    cin >> a;
    cin >> b;
    cin >> c;

    int resto = a % b;

    int position = 1;

    while (position <= b) {

        a = a * 10;

        int teste = a / b;

        a = a % b;

        if (teste == c) {
            cout << position << "\n";
            return 0;
        }

        position++;
    }

    cout << "-1" << "\n";
}