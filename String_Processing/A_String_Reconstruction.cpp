#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e6 + 5;
char ans[N], s[N];
int reach[N];

int get_r(int i) {
    if (reach[i] == i) return i;
    return reach[i] = get_r(reach[i]);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0;i < N; i++)reach[i] = i;
    while (n--) {
        scanf("%s", s); int l = strlen(s);
        int k; scanf("%d", &k);
        while (k--) {
            int x; scanf("%d", &x);
            for (int i = x; i < x + l; i = get_r(i)) {
                ans[i] = s[i - x];
                reach[get_r(i)] = get_r(i + 1);
            }
        }
    }
    int nn = N;
    while (!ans[nn])nn--;
    for (int i = 1; i <= nn; i++) {
        if (!ans[i])putchar('a');
        else putchar(ans[i]);
    }
}