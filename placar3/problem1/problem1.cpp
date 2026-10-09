# include <iostream>
# include <string>

int main() {
    std::string a;
    std::string b;

    std::cin >> a;
    std::cin >> b;

    if (a == b) {
        std::cout << a << std::endl;
    } else {
        std::cout << "1" << std::endl;
    }
}
