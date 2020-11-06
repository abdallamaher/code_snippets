#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double

inline void solve() {
    //cout << endl << endl;
    int n; cin >> n;
    ld a = 1, b = -n, c = n;
    ll discriminant = b * b - 4 * a * c;
    if (discriminant >= 0) {
        ld x = (-b + sqrt(discriminant)) / (2 * a);
        if (x >= 0) {
            //cout << "Y ";
            //cout << fixed << setprecision(10) << x << ' ' << n - x << endl;
            __mingw_printf("Y %.10Lf %.10Lf\n", x, n - x);
            return;
        }
        x = (-b - sqrt(discriminant)) / (2 * a);
        if (x >= 0) {
            //cout << "Y ";
            //cout << fixed << setprecision(10) << x << ' ' << n - x << endl;
            __mingw_printf("Y %.10Lf %.10Lf\n", x, n - x);
            return;
        }
    }
    puts("N");
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}