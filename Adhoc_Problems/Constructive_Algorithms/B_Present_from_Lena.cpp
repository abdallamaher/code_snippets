#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void print(string& s) {
    for (int j = 0; j < s.size(); j++) {
        cout << s[j] << "\n "[j != s.size() - 1];
    }
}

int main() {
    int n; cin >> n;
    vector<string> v;
    for (int i = n; i >= 0; i--) {
        string s = "";
        int x = i;
        while (x)s += ' ', x--;
        while (x < n - i) {
            s += (x + '0');
            x++;
        }
        while (x >= 0) {
            s += (x + '0');
            x--;
        }
        print(s);
        if (i)v.push_back(s);
    }
    for (int i = v.size() - 1; i>=0; i--) {
        print(v[i]);
    }
    return 0;
}