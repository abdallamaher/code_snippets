#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

int main() {
    pair<int, int> ar[4];
    for (int i = 0; i < 3; i++) {
        cin >> ar[i].F >> ar[i].S;
    }
    sort(ar, ar + 3);
    int mx_y = max({ ar[0].S, ar[1].S, ar[2].S });
    int mn_y = min({ ar[0].S, ar[1].S, ar[2].S });

    cout << (mx_y - mn_y + 1) + (ar[2].F - ar[0].F) << endl;

    for (int i = mn_y; i <= mx_y; i++) {
        cout << ar[1].F << ' ' << i << endl;
    }

    for (int i = ar[1].F + 1; i <= ar[2].F; i++) {
        cout << i << ' ' << ar[2].S << endl;
    }

    for (int i = ar[0].F; i < ar[1].F; i++) {
        cout << i << ' ' << ar[0].S << endl;
    }
}