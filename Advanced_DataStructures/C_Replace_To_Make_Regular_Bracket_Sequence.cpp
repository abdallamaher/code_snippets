#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    string s; cin >> s;
    string  a = "[{<(",
        b = "]}>)";
    string v;
    int ans = 0;
    for (auto c : s) {
        if (a.find(c) != -1)v.push_back(c);    //open
        else {  //close
            if (v.empty())return cout << "Impossible", 0;  // close no open
            char ops = a[b.find(c)];
            if (v.back() != ops)ans++;
            v.pop_back();
        }
    }
    if (v.size())cout << "Impossible";
    else cout << ans << endl;
}