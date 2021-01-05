#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, r, t;
const int N = 3e2 + 5;
int ar[N], light[2000];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> t >> r;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ar[i] += 300;
    }
    if (t < r)return cout << -1, 0;

    int cnt = 0;
    for(int i=0; i<n; i++) {
        if (light[ar[i]] >= r)continue;
        int need = r - light[ar[i]];
        cnt += need;
        while (need) {
            for (int j = ar[i] - need; j <= ar[i] - need + t; j++) {
                light[j]++;
            }
            need--;
        }
    }


    cout << cnt;
    return 0;
}

