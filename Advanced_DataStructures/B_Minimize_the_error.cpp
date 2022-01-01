#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, k1, k2; scanf("%d%d%d", &n, &k1, &k2);
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    priority_queue<int>q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        q.push(abs(a[i] - b[i]));
    }
    for (int i = 0; i < k1 + k2; i++) {
        auto cur = q.top();
        q.pop();
        if (cur > 0)cur--;
        else cur++;

        q.push(cur);
    }
    ll sum = 0;
    while (q.size()) {
        auto it = q.top();
        q.pop();
        sum += 1ll * it * it;
    }
    cout << sum << endl;
}

int solve() {
    int n, k1, k2; scanf("%d%d%d", &n, &k1, &k2);
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    multiset<int>st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        st.insert(abs(a[i] - b[i]));
    }
    for (int i = 0; i < k1 + k2; i++) {
        //cout << i << endl;
        auto lst = st.end();
        lst--;
        int x = *lst;
        st.erase(lst);
        if (x > 0)x--;
        else x++;

        st.insert(x);
    }
    ll sum = 0;
    for (auto it : st)sum += 1ll * it * it;
    cout << sum << endl;
}


int solve2() {
    int n, k1, k2; scanf("%d%d%d", &n, &k1, &k2);
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    set<pair<int, int>>st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        st.insert({ -abs(a[i] - b[i]), i });
    }
    for (int i = 0;i < k1; i++) {
        auto cur = *st.begin();
        st.erase(st.begin());
        int idx = cur.second;
        if (a[idx] > b[idx])a[idx]--;
        else a[idx]++;
 
        st.insert({ -abs(a[idx] - b[idx]), idx });
    }
    for (int i = 0;i < k2; i++) {
        auto cur = *st.begin();
        st.erase(st.begin());
        int idx = cur.second;
        if (b[idx] > a[idx])b[idx]--;
        else b[idx]++;
 
        st.insert({ -abs(a[idx] - b[idx]), idx });
    }
 
    ll sum = 0;
    for (auto it : st)sum += 1ll * it.first * it.first;
    cout << sum << endl;
}

