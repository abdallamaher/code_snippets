#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int z, o; cin >> z >> o;
    int ok = 0;
    if (z >= o) ok = bool(z - o > 1);   // 010101   // min
    else ok = bool(o > z * 2 + 2);  // 110110 11    // max
    if (ok) {   // if between it's ok
        puts("-1");
        return 0;
    }

    string s;
    while (o || z) {
        if (o && o >= z) {
            s += '1';
            o--;
        }
        if (o && o >= z) {
            s += '1';
            o--;
        }
        if (z) {
            s += '0';
            z--;
        }
    }
    if (s.find("111") != -1 || s.find("00") != -1)
        puts("-1");
    else
        cout << s << endl;
}