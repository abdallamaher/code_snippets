#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    string a, b; cin >> a >> b;
    int ok = 1;
    if (a.size() != b.size())ok = 0;
    if (b.find('1') != -1 && a.find('1') == -1)ok = 0;
    if (b.find('1') == -1 && a.find('1') != -1)ok = 0;
    puts(ok ? "YES" : "NO");
}