#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> v;
    for (int a = 0, i = 1, j = n; a < n; a++) {
        if (a & 1 ^ 1)v.push_back(i), i++;
        else v.push_back(j), j--;
    }
    sort(v.begin() + k, v.end());
    cerr << v[k] << endl;
    if (abs(v[k] - v[k - 1]) > 1)
        sort(v.begin() + k, v.end(), greater<int>());
    for (auto it : v)printf("%d ", it);
}