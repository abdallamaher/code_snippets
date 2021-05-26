#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int N = 1e5 + 5;
int ar[N];
map<int, int> mp;
set<int> st;

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        ar[i] = x;
        mp[x]++;
    }

    for (int i = 0; i <= n; i++) {
        if (mp[i] == 0)st.insert(i);
    }


    for (int i = 0;i < n; i++) {
        if (i && ar[i] != ar[i - 1])st.insert(ar[i - 1]);
        printf("%d ", *st.begin());
        st.erase(st.begin());
    }
}