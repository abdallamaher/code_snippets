#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, s; scanf("%d%d", &s, &n);
    vector<int> ar(n * s + 5);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        ar[x] = i;
    }
    vector< vector<int> > v(n + 5);
    for (int i = 1, stu = 1, cnt = 1; i <= s * n; i++) {
        if (ar[i] > 0) {
            v[ar[i]].push_back(i);
            continue;
        }
        if (cnt == s)stu++, cnt = 1;
        v[stu].push_back(i);
        cnt++;
    }
    for (auto& it : v) {
        for (auto i : it)printf("%d ", i);
        puts("");
    }
    return 0;
}