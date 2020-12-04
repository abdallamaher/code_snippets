#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    int n, s; cin >> n >> s;
    if (s - n + 1 <= n) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; i < n;i++)printf("1 ");
    printf("%d\n", s - n + 1);
    printf("%d\n", n);
}

int main() {
    int n, s; cin >> n >> s;
    if (s < 2 * n)return puts("NO"), 0;

    puts("YES");
    for (int i = 1; i < n; i++) {
        printf("2 ");
    }
    printf("%d\n", s - 2 * (n - 1));
    printf("1");
}