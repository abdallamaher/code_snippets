#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;

int main() {
    cin >> n;
    int r[n] = {};
    int c[n] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;cin >> x;
            r[i] += (x == 'C');
            c[j] += (x == 'C');
        }
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans+=1ll * r[i] * (r[i] - 1) / 2;
        ans+=1ll * c[i] * (c[i] - 1) / 2;
    }
    cout << ans << endl;
}