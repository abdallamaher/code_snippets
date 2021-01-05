#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
int n;
double mn = 1e9;
vector<double>v;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back(atan2(y, x) * 180.0 / PI);
    }
    sort(v.begin(), v.end());
    v.push_back(v[0] + 360);
    for (int i = 1; i < v.size(); i++) {
        //printf("%.15f\n", (v[i + 1] - v[i]));
        mn = min(mn, 360 - v[i] + v[i - 1]);
    }
    printf("%.15f", mn);
    return 0;
}