#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)cin >> ar[i];
    int a = 0, b = 0, f = 1, cnt = 0;
    int ansA = 0, ansB = 0;
    for (int i = 0, j = n - 1; i <= j; ) {
        cnt++;
        if (f) {
            int sum = 0;
            while (i <= j && sum <= b) {
                sum += ar[i];
                i++;
            }
            a = sum;
            ansA += sum;
        }
        else {
            int sum = 0;
            while (i <= j && sum <= a) {
                sum += ar[j];
                j--;
            }
            b = sum;
            ansB += sum;
        }
        f = 1 - f;
    }
    cout << cnt << ' ' << ansA << ' ' << ansB << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}