#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int n, ans;
int ar[N], m[N];
ll sum;

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    for (int i = 1; i < n; i++) {
        ar[i] += ar[i - 1];
    }
    for (int i = 0; i < n-1; i++) {
        if (sum - ar[i] == ar[i])ans++;
    }
    printf("%d", ans);
    return 0;
}
 


