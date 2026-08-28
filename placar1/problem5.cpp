# include <iostream>
#include <algorithm>

int main() {
    int n = 0;
    std::cin >> n;

    int pile[n];

    int w = 0; // contador de worms

    for (int i = 0; i < n; i++) {
        int a = 0;
        std::cin >> a;

        w += a;

        pile[i] = w;
    }

    int m = 0;
    std::cin >> m;

    for (int g = 0; g < m; g++) {
        int h = 0;
        std::cin >> h;

        int* pos = std::lower_bound(pile, pile + n, h);
        int f = (pos - pile) + 1;

        std::cout << f << "\n";

    }
}