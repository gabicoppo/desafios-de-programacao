#include <iostream>
#include <vector>

using namespace std;

long long divisores(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}

int main() {
    int t = 0;
    long long n = 0;
    long long k = 0;

    cin >> t;

    while (t--) {
        long long n;
        long long k;
        cin >> n;
        cin >> k;
        cout << n + divisores(n) + 2 * (k - 1) << "\n";
    }
}
