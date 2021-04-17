#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int ar[N];
int prime_num[N];

inline void sieve() {
    for (int i = 2;i * i < N; i++) {
        if (ar[i])continue;
        for (int j = i + i; j < N; j += i)ar[j] = 1;
    }
    for (int i = 2; i < N; i++) {
        prime_num[i] = prime_num[i - 1];
        if (ar[i] == 0)prime_num[i]++;
    }
}

int main() {
    sieve();
    int n; cin >> n;
    while (n--) {
        int x; scanf("%d", &x);
        printf("%d\n", prime_num[x] - prime_num[(int)sqrt(x)] + 1);
    }
}