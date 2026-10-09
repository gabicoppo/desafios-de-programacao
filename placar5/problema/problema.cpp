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


vector<int> getPrimesInRange(int L, int R) {
    vector<int> range_primes;
    for (int i = L; i <= R; i++) {
        if (bs[i]) { 
            range_primes.push_back(i);
        }
    }
    return range_primes;
}

int calculaDivisores(const vector<int> &inteiros, vector<int> primos) {
    int lenght_inteiros = inteiros.size();
    int lenght_primos = primos.size();

    int divisiveis = 0;

    for (int i = 0; i < lenght_inteiros; i++) {
        for (int j = 0; j < lenght_primos; j++) {
            if (inteiros[i] % primos[j] == 0) {
                divisiveis += 1;
            }
        }
    }
    return divisiveis;
}

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Primeira parte: Crivo de Eratóstenes
    sieve(10000000); // Até 10^7

    int n = 0;

    cin >> n;

    vector<int> inteiros(n);

    for (int i = 0; i < n; i++) {
        cin >> inteiros[i];
    }

    int m = 0;

    cin >> m;

    int L = 0;
    int R = 0;

    for (int j = 0; j < m; j++) {
        cin >> L;
        cin >> R;

        if (L > 10000000) {
            cout << 0 << "\n";
            continue;
        }

        vector<int> primos = getPrimesInRange(L, R);

        int divisiveis = calculaDivisores(inteiros, primos);

        cout << divisiveis << endl;
    }

    return 0;
}