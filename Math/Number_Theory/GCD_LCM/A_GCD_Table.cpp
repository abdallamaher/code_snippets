#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e2 + 5;

int ar[N * N];
map<int, int> cnt;
vector<int> ans;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n * n; i++) {
        scanf("%d", ar + i);
        cnt[ar[i]]++;
    }
    sort(ar, ar + n * n);
    reverse(ar, ar + n * n);
    for (int i = 0; i < n * n; i++) {
        if (cnt[ar[i]] == 0)continue;
        cnt[ar[i]]--;
        for (auto it : ans) {
            cnt[__gcd(it, ar[i])] -= 2;
        }
        ans.push_back(ar[i]);
    }
    for (auto it : ans)printf("%d ", it);
}