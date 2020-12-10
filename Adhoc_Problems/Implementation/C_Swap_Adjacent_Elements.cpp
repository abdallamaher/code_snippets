#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n; i++)scanf("%d", &v[i]);
    string s; cin >> s;

    for (int i = 0; i < n - 1; i++) {
        int j = i;
        while (s[j] == '1')j++;
        sort(v.begin() + i, v.begin() + j + 1);
        i = j;
    }
    int ok = 1;
    for (int i = 0; i < n; i++)if (v[i] != i + 1)ok = 0;
    puts(ok ? "YES" : "NO");
}