#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) { // Cria lista de primos em [0..upperbound]
    _sieve_size = upperbound + 1; // Adiciona 1 para incluir upperbound
    bs.set();                    // Define todos os bits para 1
    bs[0] = bs[1] = 0;           // Exceto os índices 0 e 1

    for (ll i = 2; i < _sieve_size; i++) { // Mantido < para evitar out-of-bounds no bitset
        if (bs[i]) {
            // Elimina os múltiplos de i a partir de i * i
            for (ll j = i * i; j < _sieve_size; j += i) {
                bs[j] = 0;
            }
            primes.push_back((int)i); // Adiciona à lista de primos
        }
    }
}

int getPrimesInRange(ll L, ll R) {
    //vector<int> range_primes;
    for (int i = L; i <= R; i++) {
        if (bs[i]) {
            cout << i << endl;
            //range_primes.push_back(i);
        }
    }
    cout << endl;
    return 0;
    //return range_primes;
}

void segmentedSieve(ll L, ll R) {
    vector<bool> is_prime_range(R - L + 1, true);

    if (L == 1) { // 1 não eh primo
        is_prime_range[0] = false;
    }

    for (size_t i = 0; i < primes.size(); i++) {
        int p = primes[i];

        if ((ll)p * p > R) {
            break; // primos > sqrt(N) não precisam testar
        }

        ll start = (L / p) * p;
        if (start < L) {
            start += p;
        }

        if (start == p) { 
            start += p;
        }

        for (ll j = start; j <= R; j += p) {
            is_prime_range[j - L] = false;
        }
    }

    // imprime
    for (ll i = L; i <= R; i++) {
        if (is_prime_range[i - L]) {
            cout << i << "\n";
        }
    }
    cout << "\n";
}

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Primeira parte: Crivo de Eratóstenes
    sieve(10000000); // Até 10^7

    ll n = 0;

    cin >> n;

    ll L = 0;
    ll R = 0;

    for (int j = 0; j < n; j++) {
        cin >> L;
        cin >> R;

        segmentedSieve(L, R);
    }

}