#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, a, b;
set<int> st;

void factors(int x) {
    for (ll i = 2;i * i <= x; i++) {
        if (x % i)continue;
        while (x % i == 0) {
            x /= i;
        }
        st.insert(i);
    }
    if (x != 1)st.insert(x);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        if (!i) {
            factors(a);
            factors(b);
            continue;
        }
        for (auto it = st.begin(); it != st.end(); ) {
            if ((a % *it) && (b % *it)) {
                st.erase(it++);
            }
            else  it++;
        }
    }

    if (st.empty()) {
        puts("-1");
    }
    else {
        printf("%d\n", *st.begin());
    }
    return 0;
}