#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    string s; int n, q;
    cin >> s >> q;
    n = s.size();
    vector<int> v(n * 2);
    for (int i = 0; i < q; i++) {
        int x; scanf("%d", &x);
        v[x-1]++;
    }
    for (int i = 1; i < n / 2; i++) {
        v[i] += v[i - 1];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] & 1)swap(s[i], s[n - i - 1]);
        cout << s[i];
    }
}