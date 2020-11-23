#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n; scanf("%d", &n);
    vector<int> v(n + 5);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            ++cnt;
            for (int j = i; j <= n; j += i)v[j] = cnt;
        }
        printf("%d ", v[i]);
    }
}