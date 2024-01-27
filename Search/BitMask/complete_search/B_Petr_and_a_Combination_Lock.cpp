#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int ar[20];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ar[i];

    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))sum += ar[i];
            else sum -= ar[i];
        }
        if ((sum % 360) == 0) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}