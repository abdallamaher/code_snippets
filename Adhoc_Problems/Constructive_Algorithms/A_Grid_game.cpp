#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    vector<int> v = { 1, 3 };
    vector<int> h = { 1, 2, 3, 4 };
    string s; cin >> s;
    int a = 0, b = 0;
    for (auto it : s) {
        if (it == '0') {
            printf("%d %d\n", v[a % 2], 1);
            a++;
        }
        else {
            printf("%d %d\n", h[b % 4], 3);
            b++;
        }
    }
}