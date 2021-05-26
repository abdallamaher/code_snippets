#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    string s, t; cin >> s >> t;
    int n = s.size() - 1;
    while (s[n] == 'z') { s[n] = 'a', n--; }
    s[n]++;
    cout << (s < t ? s : "No such string");
}