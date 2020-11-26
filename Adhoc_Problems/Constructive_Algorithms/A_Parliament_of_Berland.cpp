#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, a, b; cin >> n >> a >> b;
    if (a * b < n)return cout << -1, 0;

    vector<vector<int>> g(a, vector<int>(b));
    int odd = 1, even = 2;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if ((i + j) % 2) {
                if (even <= n)g[i][j] = even;
                even += 2;
            }
            else {
                if (odd <= n)g[i][j] = odd;
                odd += 2;
            }
        }
    }


    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << g[i][j] << ' ';
        }cout << '\n';
    }
    return 0;
}