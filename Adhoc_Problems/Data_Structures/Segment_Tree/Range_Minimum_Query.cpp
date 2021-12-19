#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int n, q;
int ar[N], seg[4 * N];
            
           // node{idx, l, r}
void build(int idx, int l, int r) {
    if (l == r) {           // base case
        seg[idx] = ar[l];
        return;
    }
    int mid = (l + r) / 2;
    build(idx * 2, l, mid);         // branch left
    build(idx * 2 + 1, mid + 1, r); // branch right

    // backtracking
    seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
}
        
int get(int idx, int l, int r, int a, int b) {
    if (a <= l && r <= b)           // {l, r} lie completely in search {a, b}  >> {a, l , r, b}
        return seg[idx];
    
    if (max(a, l) > min(b, r))      // {l, r} lie completely out search {a, b}  >> {r, a, b, l}
        return 2e9;
    
    int mid = (l + r) / 2;          // {l, r} lie partially in search {a, b}
    return min(get(idx * 2, l, mid, a, b)
        , get(idx * 2 + 1, mid + 1, r, a, b));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)cin >> ar[i];
    build(1, 0, n - 1);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << get(1, 0, n - 1, a, b) << endl;
    }
    return 0;
}