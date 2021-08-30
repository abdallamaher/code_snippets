#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
char s[N], ans[N], mn[N];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    mn[n] = 'z' + 1;
    for (int i = n - 1; i >= 0; i--) {
        mn[i] = min(mn[i + 1], s[i]);
    }
    stack<char> st;
    int j = 0;
    for (int i = 0; i < n; i++) {
        st.push(s[i]);
        while (st.size() && st.top() <= mn[i + 1]) {
            ans[j++] = st.top();
            st.pop();
        }
    }
    printf("%s\n", ans);
}