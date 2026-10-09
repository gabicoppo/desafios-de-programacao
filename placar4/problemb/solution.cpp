#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    double r = a / b;
    double z = c / d;

    double result = r / (1 - (1 - r) * (1 - z));
    cout << fixed << setprecision(12) << result << "\n";
}