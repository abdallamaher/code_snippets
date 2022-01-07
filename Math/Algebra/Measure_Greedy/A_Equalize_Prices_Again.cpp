#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
inline void solve() {
	int n; cin >> n;
    ll sum = 0;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        sum += x;
    }
    cout << (sum + n - 1) / n << endl;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}