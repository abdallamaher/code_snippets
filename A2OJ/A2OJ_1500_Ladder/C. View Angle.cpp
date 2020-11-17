#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<double> angles;
const double pi = acos(-1);

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        angles.push_back(atan2(y, x) * 180.0 / pi);
    }
    sort(angles.begin(), angles.end());
    angles.push_back(angles[0] + 360.0);
    double mx = 0.0;

    for (int i = 1; i < angles.size(); i++) {
        mx = max(angles[i]-angles[i-1], mx);
    }
    printf("%.10f", 360.0-mx);
    return 0;
}
 