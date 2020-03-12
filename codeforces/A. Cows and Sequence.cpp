#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
const int OO = (int)1e9;
ll sum;
int n, t, a, b;
vector<int>v;
int mark[N];
int main() {
    cin.sync_with_stdio(false);
    v.push_back(0);
    cin >> n;
    while (n--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            sum += 1ll * b * a;
            mark[a] += b;
        }
        else if (t == 2) {
            cin >> a;
            sum += a;
            v.push_back(a);
        }
        else  {
            int t = v.size();
            sum -= 1ll * v[t-1] + mark[t];
            mark[t - 1] += mark[t];
            mark[t] = 0;
            v.pop_back();
        }

        printf("%.6f\n",sum * 1.0 / v.size());
    }
    return 0;
}





