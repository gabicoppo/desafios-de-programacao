#include <iostream>
#include <string>

int main()
{
    int s = 0;
    int n = 0;
    int doisn = 0;

    std::cin >> s;
    std::cin >> n;
    
    doisn = n + n;

    int foo [doisn];

    for (int j = 0; j < doisn; j++) {
        std::cin >> foo[j];
    }

    for (int i = 0; i < doisn; i+=2) {
        if (foo[i] == -1) {
            continue;
        }
        if (foo[i] < s) {  // se o fighter puder vencer, somamos a força, setamos o fighter como -1 e reiniciamos o loop
            foo[i] = -1;
            s += foo[i + 1];
            i = -2;
            continue;
        } 
    }

    for (int i = 0; i < doisn; i+=2) {
        if (foo[i] != -1) {
            std::cout << "NO";
            return 0;
        }
    }
    
    std::cout << "YES";
    
    return 0;

}