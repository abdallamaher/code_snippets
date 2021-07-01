#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second


int main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        v[i] = { x, i + 1 };
    }

    sort(v.begin(), v.end());


    // all is good - first is bad
    // one is bad  not [1, 2, 3]
    int start = v[0].f;
    int diff = v[1].f - v[0].f;
    int countBad = 0;
    int badEl = v[0].s;
    for (int i = 1; i < n;i++) {
        if (v[i].f != start + diff * (i - countBad)) {
            countBad++;
            badEl = v[i].s;
        }
    }
    if (countBad <= 1) {
        cout << badEl << endl;
        return 0;
    }


    // 1 is bad
    start = v[0].f;
    diff = v[2].f - v[0].f;
    countBad = 0;
    badEl = v[1].s;
    for (int i = 2; i < n;i++) {
        if (v[i].f != start + diff * (i - 1)) {
            countBad++;
        }
    }
    if (countBad == 0) {
        cout << badEl << endl;
        return 0;
    }


    // 2 is bad
    start = v[1].f;
    diff = v[2].f - v[1].f;
    countBad = 0;
    badEl = v[0].s;
    for (int i = 2; i < n;i++) {
        if (v[i].f != start + diff * (i - 1)) {
            countBad++;
        }
    }
    if (countBad == 0) {
        cout << badEl << endl;
        return 0;
    }


    cout << -1 << endl;
}