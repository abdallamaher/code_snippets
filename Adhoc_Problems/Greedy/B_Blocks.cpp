#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
int n; string s;
int ar[205];

inline void solve(int x) {
    for (int i = 0;i < n; i++) {
        if (s[i] == 'B')ar[i] = 1;
        else ar[i] = 0;
    }
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        if (ar[i] != x) {
            ans.push_back(i);
            ar[i] = 1 - ar[i];
            ar[i + 1] = 1 - ar[i + 1];
        }
    }
    if (ar[n - 1] == x) {
        cout << ans.size() << endl;
        for (auto it : ans)cout << it + 1 << ' ';
        exit(0);
    }
}

int main() {
    cin >> n >> s;
    solve(1);
    solve(0);
    cout << -1 << endl;
    return 0;
}