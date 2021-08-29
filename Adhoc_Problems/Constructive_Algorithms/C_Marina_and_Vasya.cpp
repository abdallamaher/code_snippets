#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
string s1, s2, s;


int main() {
    cin >> n >> k >> s1 >> s2;

    // construct s to be all_diff
    auto get_diff = [&](char x, char y) {
        char res;
        for (char i = 'a'; i < 'e'; i++) {
            if (i != x && i != y) {
                res = i;
                break;
            }
        }
        return res;
    };
    for (int i = 0; i < n; i++) {
        s += get_diff(s1[i], s2[i]);
    }

    // fill in same first
    int same_res_both = n - k;
    for (int i = 0;i < n;i++) {
        if (s1[i] == s2[i] && same_res_both) {
            s[i] = s1[i];
            same_res_both--;
        }
    }
    // fill in diff
    int a, b;
    a = b = same_res_both;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i])continue;

        if (a)s[i] = s1[i], a--;
        else if (b)s[i] = s2[i], b--;
    }

    if (a || b)puts("-1");
    else cout << s << endl;
}