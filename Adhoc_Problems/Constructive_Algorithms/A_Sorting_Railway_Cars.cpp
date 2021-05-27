#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e5 + 5;
int pos[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        pos[x] = i;
    }
    
    int LIConsgative = 1;

    for (int i = 2, cnt = 1; i <= n; i++) {
        if (pos[i - 1] < pos[i])cnt++;
        else cnt = 1;
        LIConsgative = max(cnt, LIConsgative);
    }

    printf("%d\n", n - LIConsgative);
    return 0;
}