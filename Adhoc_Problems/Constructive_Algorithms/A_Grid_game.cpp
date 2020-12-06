#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    vector<pair<int, int>> v = { {1,1}, {3, 1} };
    vector<pair<int, int>> h = { {1, 3}, {2, 3},{3, 3},{4, 3} };
    string s; cin >> s;
    int a = 0, b = 0;
    for (auto it : s) {
        if (it == '0') {
            printf("%d %d\n", v[a % 2].first, v[a % 2].second);
            a++;
        }
        else {
            printf("%d %d\n", h[b % 4].first, h[b % 2].second);
            b++;
        }
    }
}