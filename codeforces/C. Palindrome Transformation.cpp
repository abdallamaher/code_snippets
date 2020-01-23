#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4e2 + 5;
const int mod = (int)1e9 + 7;

string s;
int p, n, ans, mn, mx;

int small (char f, char ss){
    int d = abs(f - ss);
    return d = min(d, 26 - d);
}

int main() {
    cin >> n >> p >> s;
    p--; n--;
    if(p > n/2) {
        reverse(s.begin(), s.end());
        p = n-p;
    }
    for(int i=p; i<=n/2; i++) {
        if(s[i] != s[n-i]){
            ans += small(s[i], s[n-i]);
            mn = abs(i-p);
        }
    }
    for(int j=p-1; j>=0; j--) {
        if(s[j] != s[n-j]) {
            ans += small(s[j], s[n-j]);
            mx = abs(j-p);
        }
    }
    if(mn > mx)swap(mx, mn);
    printf("%d\n", 2*mn+mx+ans);
    return 0;
}


