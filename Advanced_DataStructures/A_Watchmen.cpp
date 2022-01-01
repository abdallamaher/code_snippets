#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n; cin >> n;
    map<int, ll> mpX, mpY;
    map< pair<int, int>, ll> f;
    ll sum = 0;
    while (n--) {
        int x, y; scanf("%d %d", &x, &y);
        f[{x, y}]++;
        mpX[x]++;
        mpY[y]++;
    }
    for (auto it : mpX) {
        sum += (it.second - 1) * it.second / 2;
    }
    for (auto it : mpY) {
        sum += (it.second - 1) * it.second / 2;
    }
    for (auto it : f)if (it.second > 1) {
        sum -= (it.second - 1) * it.second / 2;
    }
    cout << sum;
}