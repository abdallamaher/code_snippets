#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
const int N = 1e5 + 7;

int gender;
vector<int> v;
string M[] = { "lios", "etr", "initis" };
string F[] = { "liala", "etra", "inites" };

bool ok(string& s1, string& s2) {
    if (s1.size() < s2.size())return 0;
    int i = s1.size() - 1, j = s2.size() - 1;
    while (i >= 0 && j >= 0) {
        if (s1[i] == s2[j]) 
            i--, j--;
        else
            return 0;
    }
    return 1;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    string st, s;
    getline(cin, st);
    stringstream is(st);
    while (is >> s) {
        int f = 1;
        for (int i = 0; i < 3; i++) {
            if (ok(s,F[i])) {
                f = 0;
                if (gender == 2)return puts("NO"), 0;
                gender = 1;
                v.push_back(i);

            }
            else if (ok(s,M[i])) {
                f = 0;
                if (gender == 1)return puts("NO"), 0;
                gender = 2;
                v.push_back(i);
            }
        }
        if (f)return puts("NO"), 0;
    }
    if (v.size() == 1)return puts("YES"), 0;
    int f = 0;
    for (int i = 0; i < v.size(); ++i) {
       if (v[i] == 1)f++;
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i-1] || !f || f>1) {
            return puts("NO"), 0;
        }
    }
    puts("YES");
    return 0;
}