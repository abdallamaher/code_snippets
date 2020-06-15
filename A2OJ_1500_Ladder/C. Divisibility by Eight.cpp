#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
void check(string ss) {
    int a = 0, b = 0;
    for (; ss[a] && s[b]; b++) {
        if (ss[a] == s[b]) {
            a++;
        }
    }
    int x;
    stringstream stream(ss);
    stream >> x;
    //printf("%s %d %d\n",ss.c_str(), a, x);
    if (x % 8==0 && a == ss.size()) {
        cout << "YES\n" << x;
        exit(0);
    }
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (char i = '0'; i <= '9'; i++) {
        string ss = "";
        ss += i;
        check(ss);
        for (char j = '0';j <= '9'; j++) {
            string ss = "";
            ss += i;
            ss += j;
            check(ss);
            for (char k = '0'; k <= '9'; k++) {
                string ss = "";
                ss += i;
                ss += j;
                ss += k;
                check(ss);
            }
        }
    }
    cout << "NO";
    return 0;
}