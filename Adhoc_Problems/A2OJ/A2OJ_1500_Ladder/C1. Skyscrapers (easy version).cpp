#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 1e3 + 5;
int ar[N], b[N];
int pr;
ll sum;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ll mn = 0;
    for (int i = 0; i < n; i++) {
        mn = 0; pr = ar[i];
        for (int j = i; j < n; j++) {
            int m = min(ar[j], pr);
            mn += m;
            pr = m;
        }
        pr = ar[i];
        for (int j = i - 1; j >= 0; j--) {
            int m = min(ar[j], pr);
            mn += m;
            pr = m;
        }
        sum = max(mn, sum);
    }
    for (int i = 0; i < n; i++) {
        mn = 0; pr = ar[i];
        for (int j = i; j < n; j++) {
            int m = min(ar[j], pr);
            mn += m;
            pr = m;
            b[j] = m;
        }
        pr = ar[i];
        for (int j = i - 1; j >= 0; j--) {
            int m = min(ar[j], pr);
            mn += m;
            pr = m;
            b[j] = m;
        }
        if (mn == sum)break;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    return 0;
}