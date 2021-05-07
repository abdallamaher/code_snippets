#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5 + 5;

multiset<int> sl, sr;

struct Node
{
    int a;
    int b;
} ar[N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n;i++) {
        int a, b; scanf("%d %d", &a, &b);
        ar[i].a = a;
        ar[i].b = b;
        sl.insert(a);
        sr.insert(b);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sl.erase(sl.find(ar[i].a));
        sr.erase(sr.find(ar[i].b));
        int l = *sl.rbegin();
        int r = *sr.begin();
        ans = max(ans, r - l);
        sl.insert(ar[i].a);
        sr.insert(ar[i].b);
    }
    printf("%d\n", ans);
}
