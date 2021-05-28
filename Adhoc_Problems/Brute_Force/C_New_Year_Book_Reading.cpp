#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
const int N = 1e3 + 5;
int w[N];
int dy[N];
int vis[N];
vector<int> v;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)scanf("%d", w + i);
    for (int i = 0; i < m; i++) {
        scanf("%d", dy + i);
        if (vis[dy[i]] == 0)v.push_back(dy[i]);     //greedy
        vis[dy[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {       // brute
        for (int j = 0; j < v.size(); j++) {
            if (v[j] == dy[i]) {
                for (int f = j; f > 0; f--)swap(v[f], v[f - 1]);
                break;
            }
            else {
                ans += w[v[j] - 1];
            }
        }
    }

    printf("%d\n", ans);

}