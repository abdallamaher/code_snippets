#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    string s; cin >> s;
    int ok = 0;
    for (int i = 1; i < s.size(); i++) {
        ok |= (islower(s[i]));
    }
    if (!ok){
        for (auto& c : s) c ^= 32;
        // {
        //     if (islower(c)) c = toupper(c);
        //     else c = tolower(c);
        // }
    }
    cout << s << endl;
    return 0;
}