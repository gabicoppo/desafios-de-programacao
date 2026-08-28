#include <iostream>
#include <string>

int main()
{
    long long t = 0;
    long long c = 0;

    std::cin >> t;

    for (auto i = 0; i < t; ++i) {
        auto n = 0;

        std::cin >> n;

        long long foo [n];

        for (auto j = 0; j < n; j++) {
            std::cin >> foo[j];
        }
        long long f = 0;

        f = foo[n - 1];

        if (n > 2) {
            for (auto i = n - 2; i >= 1; i--) {
                long long a = 0;
                long long b = 0;

                a = foo[i];
                b = foo[i - 1];

                c = a - b;

                foo [i - 1] = c;
            }
        } else {
            c = foo[0];
            long long d = 0;
            d = f - c;
            std::cout << d << "\n";
            continue;
        };

        long long g = 0;
        g = f - c;

        std::cout << g << "\n";
    }
}