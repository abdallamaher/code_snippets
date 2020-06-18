#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n;
ll sum;
ll mx = -1e15;
vector<int>v;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x & 1)v.push_back(x);
        else if (x > 0)sum += x;
    }
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if(sum &1)
            mx = max(mx, sum);
    }
    cout << mx;
    return 0;
}
 