#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<string> ar(n + 1, string(50, 'a'));
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            ar[i + 1][j] = ar[i][j];
        }
        ar[i + 1][x] = ar[i][x] + 1;
        if (ar[i + 1][x] > 'z')ar[i + 1][x] = 'a';
        cout << ar[i] << endl;
    }
    cout << ar[n] << endl;
}

void go() {
    int n; cin >> n;
    string s(50, 'a');
    cout << s << endl;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s[x] = (s[x] == 'a' ? 'b' : 'a');
        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)go();
}