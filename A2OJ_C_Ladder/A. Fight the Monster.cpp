#include <bits/stdc++.h>
using namespace std;
#define ll long long
int hy, ay, dy, hm, am, dm, h, a, d;
int main() {
    cin >> hy >> ay >> dy
        >> hm >> am >> dm
        >> h >> a >> d;
    int ans = 123456;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            int an = ay + i, dn = dy + j;
            int hyy = hy, hmm = hm;
            if (an - dm <= 0)continue;
            while (hmm>0) {
                hyy -= max(am - dn, 0);
                hmm -= an - dm;
            }
            int f = 0;
            if(hyy<=0)f= abs(hyy) + 1;
            ans = min(ans, f * h+ i * a+ j * d);
        }
    }
    cout << ans;
    return 0;
}