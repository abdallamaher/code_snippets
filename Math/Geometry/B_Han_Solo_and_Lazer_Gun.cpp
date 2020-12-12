#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

 
int main() {
    int n, x, y;cin >> n >> x >> y;
    set<ld> s;
    int f = 0;
    while(n--){
        int xx, yy; scanf("%d%d", &xx, &yy);
        if(xx == x){
            f = 1;
            continue;
        }
        ld slope = 1.0L * (y - yy) / (x - xx);
        s.insert(slope);
    }
    cout << s.size() + f << endl;
}