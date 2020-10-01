#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    ll m = ((s[0] - '0') + 1) * llround(pow(10, s.size() - 1));
    ll n; sscanf(s.c_str(), "%lld", &n);
    printf("%lld\n", m - n);
    return 0;
}