#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; scanf("%d", &n);
    int ar[4] = {};
    for (int i = 0; i < n;i++) {
        int x; scanf("%d", &x);
        ar[x]++;
    }
    sort(ar, ar + 4);
    printf("%d", ar[1] + ar[2]);
    return 0;
}