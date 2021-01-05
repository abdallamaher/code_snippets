#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
int ar[(int)1e5 + 5];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        ar[i] = i;
    }
    for (int i = k + 1; i >= 1; i--) {
        cout << i << ' ';
    }
    for (int i =  k + 2; i <= n; i++) {
        cout << i << ' ';
    }
    return 0;
}

/*
int ar[(int)1e5 + 5];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        ar[i] = i;
    }
    reverse(ar+1, ar + k + 2);
    for (int i =  1; i <= n; i++) {
        cout << ar[i] << ' ';
    }
    return 0;
}
*/