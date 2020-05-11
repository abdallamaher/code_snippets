#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int idx;
string ans, s, tmp;
vector<char> v;

bool solve() {
    if (idx >= v.size())return 0;
    if (v[idx] == 'p') {
        ans += "pair<";
        idx++;
        if (solve())ans += ",";
        else return 0;
        if (solve())ans += ">";
        else return 0;
        return 1;
    }
    else {
        idx++;
        ans += "int";
        return 1;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    getline(cin, tmp);    
    getline(cin, s);
    stringstream ss(s);
    while(ss >> tmp) {
        if (tmp[0] == 'p')v.push_back('p');
        else v.push_back('i');
    }
    if (solve() && idx == v.size())cout << ans;
    else cout << "Error occurred";
    return 0;
}