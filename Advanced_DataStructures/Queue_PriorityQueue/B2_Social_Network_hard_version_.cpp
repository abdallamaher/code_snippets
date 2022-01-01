#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    deque<int> q;
    set<int> st;
    for (int i = 0; i < n;i++) {
        int x; cin >> x;
        if (q.size() == k) {
            if (st.count(x) == 0) {
                int f = q.front();
                st.erase(st.find(f));
                q.pop_front();
                q.push_back(x);
                st.insert(x);
            }
        }
        else {
            if (st.count(x) == 0) {
                q.push_back(x);
                st.insert(x);
            }
        }
    }
    cout << q.size() << endl;
    for (auto it = q.rbegin(); it != q.rend(); it++)
        cout << *it << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}