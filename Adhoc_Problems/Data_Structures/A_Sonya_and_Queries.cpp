#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
#define ld long double


void solve() {
    int n; cin >> n;
    unordered_map<string, ll> mp;
    while (n--) {
        char c; string s; cin >> c >> s;
        reverse(s.begin(), s.end());
        if (c == '?') {
            while (s.size() > 1 && s.back() == '0')s.pop_back();
            cout << mp[s] << endl;
        }
        else {
            string tmp;
            int last_odd = 0;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] & 1) {
                    last_odd = i;
                    break;
                }
            }
            for (int i = 0; i < 20; i++) {
                if (i <= last_odd)tmp.push_back(s[i] & 1 + '0');
                else tmp.push_back('0');
                if (tmp.size() >= last_odd + 1)mp[tmp] += (c == '+') ? 1 : -1;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    unordered_map<string, ll> mp;
    while (n--) {
        char c; string s; cin >> c >> s;
        reverse(s.begin(), s.end());

        if (c == '?') {
            while (s.size() != 20)s.push_back('0');
            cout << mp[s] << endl;
        }
        else {
            string tmp;
            for (int i = 0; i < 20; i++) {
                if (i < s.size())tmp.push_back(s[i] & 1 + '0');
                else tmp.push_back('0');
            }
            mp[tmp] += (c == '+') ? 1 : -1;
        }
    }
}