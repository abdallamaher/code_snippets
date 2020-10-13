#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    int ar[200] = {};
    int ok = 1;
    while (n--) {
        int x; scanf("%d", &x);
        ar[x]++;
        if (x == 25)continue;
        else if (x == 50 && ar[25])ar[25]--;
        else if (x == 100 && ar[50] && ar[25])ar[50]--, ar[25]--;
        else if (x == 100 && ar[25] > 2)ar[25] -= 3;
        else ok = 0;
    }
    puts(ok ? "YES" : "NO");
    return 0;
}