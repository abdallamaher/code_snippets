#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, a, b, x, y;
    scanf("%d%d%d%d%d", &n, &a, &b, &x, &y);
    x = a - x, y = b - y;
    double dis = sqrt(1.0 * x * x + 1.0 * y * y);
    cout << (int)ceil(dis / (2 * n)) << endl;
    return 0;
}