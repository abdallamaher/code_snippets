#include<bits/stdc++.h>
using namespace std;
#define ld long double 

int main() {
    double a, b, c, x, y, d; cin >> a >> b >> c >> d;
    x = (1 - (a / b)), y = (1 - (c / d));   // prob event prim `
    double lose = x * y;    // independent so *
    double win = a / b;
    cout << fixed << setprecision(12) << win / (1.0 - lose);    // summation of infinite geometric
    return 0;
}