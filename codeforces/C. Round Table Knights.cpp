#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n;
int ar[N];

bool can(int i) {
    for (int j = 0; j < i; j++) {
        int f = 0, cnt = 0;
        for (int x = j; x < n; x += i) {
            if (!ar[x]) f = 1;
            ++cnt;
        }
        if (!f && cnt > 2) {
            return 1;
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i * i <= n; i++) {
        if (n % i)continue;
        if (can(i) || can(n / i)) {
            return puts("YES"), 0;
        }
    }
    puts("NO");
    return 0;
}