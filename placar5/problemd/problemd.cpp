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

bool isPrime(ll N) { // Testador determinístico de primalidade
    if (N < _sieve_size) return bs[N]; // O(1) para primos pequenos
    for (int i = 0; i < (int)primes.size(); i++) {
        if (N % primes[i] == 0) return false;
    }
    return true; // Demora mais tempo se N for um primo grande
}


int main () {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Primeira parte: Crivo de Eratóstenes
    sieve(10000000); // Até 10^7

    int n = 0;



    cin >> n;

    if (n == 1) {
        cout << "1" << endl;
        cout << "1" << endl;
        return 0;
    }

    if (n == 2) {
        cout << "1" << endl;
        cout << "1 1" << endl;
        return 0;
    }

    cout << "2" << endl;

    for (int i = 2; i <= n + 1; i++) {
        if (isPrime(i) == true) {
            cout << "1 "; 
        } else {
            cout << "2 "; 
        }
    }

    return 0;
}