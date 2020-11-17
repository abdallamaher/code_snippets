#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int k;
vector<int> ar;
vector<int> v;

int solve(int small = 0, int big = 0, int last = 0, int rem = k) {
    if (rem == 0)return 1;

    int ret = 0;
    for (auto it : ar) {
        if (it == last || small+it <= big)continue;
        ret = solve(big, small+it, it, rem - 1);
        if (ret) {
            v.push_back(it);
            break;
        }
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> k;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1')ar.push_back(i + 1);
    if (!solve())return cout << "NO", 0;
    cout << "YES\n";
    for (int i = v.size() - 1; i >= 0; i--)cout << v[i] << ' ';
    return 0;
}