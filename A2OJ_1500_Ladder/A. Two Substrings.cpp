#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
string s1 = "ABBA", s2 = "BAAB";

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int j = 0, i=0;
    while (i<s.size() && j<s1.size()) {
        //cout << i << ' ' << j << endl;
        if (s[i] == s1[j] && s[i + 1] == s1[j + 1]) {
            i ++;
            j += 2;
        }
        i++;
    }
    //puts("her");
    int x = 0; i = 0;
    while (i < s.size() && s2[x]) {
        if (s[i] == s2[x] && s[i + 1] == s2[x + 1]) {
            i ++;
            x += 2;
        }
        i++;
    }
    //cout << j << ' ' << x;
    if (j == 4 || x == 4)cout << "YES";
    else cout << "NO";
    return 0;
}


/*
ABABA
*/






