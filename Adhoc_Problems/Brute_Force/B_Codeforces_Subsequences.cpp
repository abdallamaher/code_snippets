#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ar[10];
string s = "codeforces";

ll get() {
    ll res = 1;
    for (int i = 0; i < 10; i++) {
        res *= ar[i];
    }
    return res;
}

int main() {
    ll n; cin >> n;
    for (int i = 0; get() < n; i = (i + 1) % 10) {
        ar[i]++;
    }
    for (int i = 0; i < 10;i++)cout << string(ar[i], s[i]);
}