#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> ar(n + 5);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    sort(ar.begin(), ar.begin() + n);
    int ok = 0;
    for (int i = 2; i < n;i++) {
        //cout << ar[i] <<  ' ' << i;
        if (ar[i] < ar[i - 1] + ar[i - 2])ok = 1;
    }
    puts(ok ? "YES" : "NO");
    return 0;
}