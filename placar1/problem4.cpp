# include <iostream>
# include <string>

int main() {
    long long n = 0;

    std::cin >> n;

    long long foo[n];

    for (long long i = 0; i < n; i++) {
        std::cin >> foo[i];
    }

    long long k = 0; // ponteiro q vai começar do início
    long long m = n - 1; // ponteiro q vai começar do final

    long long sum1 = 0;
    long long sum3 = 0;
    long long last_equal_sum = 0;

    while (k <= m) {

        if (sum1 > sum3) {
            sum3 += foo[m];
            m -= 1;

        } else if (sum3 > sum1) {
            sum1 += foo[k];
            k += 1;

        } else { // se sum1 e 3 forem iguais
                sum1 += foo[k];   // continua crescendo o lado esquerdo
                k += 1;
        }

        if (sum1 == sum3) {
            last_equal_sum = std::max(last_equal_sum, sum1);
        }

    }
    std::cout << last_equal_sum; // se só tiver um elemento 
}