#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; 
    
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int m; 
        cin >> m;

        vector<int> vector(m, 0);

        for (int i = 0; i < n; i++) {
            long long a; 
            cin >> a;

            vector[a % m]++;
        }

        int res = 0;

        if (vector[0] > 0) {
            res++;  
        }   

        for (int r = 1; r <= m - r; r++) {
            int s = m - r;

            if (r == s) {                            
                if (vector[r] > 0) res++;
            } else {
                int x = vector[r];
                int y = vector[s];

                if (x + y > 0) {
                    res += max(1, abs(x - y));
                }
            }
        }
        cout << res << "\n";
    }
}