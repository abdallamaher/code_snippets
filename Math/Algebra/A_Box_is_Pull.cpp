#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int t; cin >> t;
    while(t--){
        int x1, x2, y2,y1; cin >> x1 >> y1 >> x2 >> y2;
        int ans = abs(x1 - x2) + abs(y1 - y2);
        if(x1 != x2 && y1 != y2) ans+=2;
        cout <<  ans  << '\n';
    }
    
    return 0;
}