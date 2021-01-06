#include <bits/stdc++.h>
using namespace std;
#define ll long long

int get(string& a, string& b, int t) {
    int x = 0, y = 0, len = 0;
    for (int i = 0; a[i]; i++)x = x * t + (a[i] - '0');
    for (int i = 0; b[i]; i++)y = y * t + (b[i] - '0');
    for (int i = x + y; i; i /= t)len++;
    return len;
}

int main() {
    string a, b; cin >> a >> b;
    int mx = max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end())) - '0' + 1;
    int ans = 0;
    for (int i = mx; i <= 1000; i++) {
        ans = max(ans, get(a, b, i));
    }
    cout << ans << endl;
}