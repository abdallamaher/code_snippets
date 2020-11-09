#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    int sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    if (sum % n == 0)cout << n << endl;
    else cout << n - 1 << endl;

    return 0;
}