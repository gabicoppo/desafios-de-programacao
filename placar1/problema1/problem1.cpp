#include <iostream>
#include <string>

int main()
{
    auto n = 0;
    auto q = 0;
    auto m = 0;

    std::cin >> n;

    for (auto i = 0; i < n; ++i) {
            auto a = 0;
            auto b = 0;
            auto c = 0;

            std::cin >> a >> b;

            c = b - a;

            q = q + c;

            if (q>m) {
                m = q;
            } else {
                continue;
            }


        }


    std::cout << m << "\n";

    return 0;
}
