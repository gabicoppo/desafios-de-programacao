#include <vector>
#include <iostream>

const int MAX = 1000000;
int divide[MAX];

using namespace std;

int main() {
    int n = 0;

    cin >> n;

    int max_betinhas = -1;
    int melhorX = 2;

    for (int g = 0; g < n; g++) {
        int f;
        cin >> f;
        divide[f]++;
    }


    for (int i = 2; i <= MAX; i++) {
        int betinhas = 0;
        for (int j = i; j <= MAX; j += i) {
            betinhas += divide[j];
        }

        if (betinhas >= max_betinhas) {
            max_betinhas = betinhas;
            melhorX = i;
        }
    }



    cout << melhorX;

}