#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    ll sm1 = 0, sm2 = 0;
    string ans;
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        if (abs(sm2 - sm1 - a) <= 500)
            sm1 += a, ans.push_back('A');
        else
            sm2 += b, ans.push_back('G');
    }
    cout << ans << endl;
}