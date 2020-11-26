#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> v;
        int i = 0;
        while(i <= 10000){
            v.push_back(2 + i * x);
            i++;
        }
        cout << lower_bound(v.begin(), v.end(), n) - v.begin() + 1 << endl;
    }
    
	return 0;
}