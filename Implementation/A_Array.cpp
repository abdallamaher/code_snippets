#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> pos, neg, z;
    int f = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if (x > 0)pos.push_back(x);
        if (x < 0)neg.push_back(x);
        else if (x == 0) z.push_back(x);
    }

    if (neg.size() & 1 ^ 1) {
        z.push_back(neg.back());
        neg.pop_back();
    }

    if (pos.size() == 0) {
        pos.push_back(neg.back());
        neg.pop_back();
        pos.push_back(neg.back());
        neg.pop_back();
    }

    printf("%d ", neg.size());
    for (auto it : neg)printf("%d ", it);
    puts("");

    printf("%d ", pos.size());
    for (auto it : pos)printf("%d ", it);
    puts("");

    printf("%d ", z.size());
    for (auto it : z)printf("%d ", it);
    puts("");
    return 0;
}