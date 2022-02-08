#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
inline void solve() {
	int n; cin >> n;
    if(n == 1){
        cout << -1 << endl;
        return;
    }
    cout << 4;
    while(--n)cout << 3;
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}