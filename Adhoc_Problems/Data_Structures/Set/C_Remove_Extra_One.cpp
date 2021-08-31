#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e5 + 5;
int ar[N];
int pos[N];
int good[N];
int good_if_remove[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
        pos[ar[i]] = i;
    }
    set<int> st;
    for (int i = 0; i < n; i++) {
        auto it = st.lower_bound(ar[i]);
        if (it == st.end()) good[i] = 1;
        else {
            it++;
            if (it == st.end()) {
                it--;
                good_if_remove[pos[*it]]++;
            }
        }
        st.insert(ar[i]);

        if (i)good[i] += good[i - 1];
    }

    // auto get = [](int i) {
    //     if (i)return good[i - 1];
    //     return 0;
    // };

    int mx = -1;
    int ans = INT_MAX;
    for (int i = 0;i < n; i++) {
        int tmp = good[n - 1] - good[i] + good[i - 1] + good_if_remove[i];
        if (tmp > mx) {
            mx = tmp;
            ans = ar[i];
        }
        else if (tmp == mx) {
            ans = min(ans, ar[i]);
        }
    }
    cout << ans << endl;
}