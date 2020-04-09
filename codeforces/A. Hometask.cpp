#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

string s;
int n, ans;
map<char, char>m;
int main() {
    cin.sync_with_stdio(false);
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        m[a] = b;
        m[b] = a;
    }
    for (int i = 0; i < s.size(); i++) {
        int j;
        for (j = i + 1; j < s.size(); j++) {
            if (s[i] != s[j] && s[j] != m[s[i]])break;
        }
        j--;
        int s1=0, s2=0;
        for (int a = i; a <= j; a++) {
            if (s[a] == s[i])s1++;
            else s2++;
        }
        ans += min(s1, s2);
        i = j;
    }
    cout << ans;
    return 0;
}