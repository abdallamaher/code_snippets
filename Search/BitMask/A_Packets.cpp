#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n; cin >> n;
    for (int i = 30;i >= 0; i--) {
        //cout << i << ' ' << (1 << i) << endl;
        if ((1 << i) & n) {
            cout << i + 1 << endl;
            break;
        }
    }
    
    return 0;
    cout << 32 - __builtin_clz(n) << endl;
    return 0;
}