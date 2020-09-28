#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(auto &it: v)cin >> it;
        sort(v.begin(), v.end());
        ll cnt = 0;
        for(int i=1; i<n; i++){
            cnt += (k - v[i]) / v[0];
        }
        cout << cnt << endl;
    }
    
	return 0;
}