#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    string s, st; cin >> s >> st;
    int n = s.size(), m = st.size();
    if (s == st)cout << -1;
    else cout << max(n, m);
    return 0;
}