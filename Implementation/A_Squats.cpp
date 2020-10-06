#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; scanf("%d", &n);
    string s; cin >> s;
    int cap = 0, sm = 0;
    for (auto c : s) {
        if (islower(c))++sm;
        else ++cap;
    }
    //cout << sm << ' ' << cap << endl;
    int x = max(sm, cap) - n / 2, f = bool(sm > cap);
    cout << x << endl;
    for (auto& c : s) {
        if (!x)break;
        if (!f && isupper(c))c = tolower(c), --x;
        if (f && islower(c))c = toupper(c), --x;
    }
    cout << s << endl;
    return 0;
}