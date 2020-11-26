#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1){
            cout << -1 << endl;
            continue;
        }
        string s(n, '3');
        s[0] = '2';
        cout << s << endl;
    }
    return 0;
}