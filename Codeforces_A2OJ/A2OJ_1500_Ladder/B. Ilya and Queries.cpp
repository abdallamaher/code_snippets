#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int q, l, r;
int sum[(int)1e5 + 5];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> q;
    for (int i = 2; i<= s.size(); i++) {
        sum[i] = sum[i - 1];
        if (s[i-1] == s[i - 2]) 
            sum[i]++;
    }

    while(q--) {
        cin >> l >> r;
        cout << sum[r] - sum[l] << endl;
    }
    return 0;
}
