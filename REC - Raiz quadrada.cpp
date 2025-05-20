#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double raiz(double x, double x0, double y) {
    if (fabs(x0 * x0 - x) <= y) {
        return x0;
    } else {
        double x1 = (x0 + x / x0) / 2;
        return raiz(x, x1, y);
    }
}

int main() {
    double x, x0, y;
    cin >> x >> x0 >> y;
    
    double resultado = raiz(x, x0, y);
    cout << fixed << setprecision(4) << resultado << endl;
    
    return 0;
}
