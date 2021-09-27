#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
const int N = 1e5 + 5;
const int ab = 3, ba = 3;
int dp[N][ab][ba];


int solve(int i, int ab = 0, int ba = 0) {
    if (i >= s.size() - 1) {
        return ab && ba;
    }
    int& ret = dp[i][ab][ba];
    if (~ret)return ret;
    ret = solve(i + 1, ab, ba);
    if (s[i] == 'A' && s[i + 1] == 'B') ret |= solve(i + 2, 1, ba);
    else if (s[i] == 'B' && s[i + 1] == 'A') ret |= solve(i + 2, ab, 1);
    return ret;
}

int main() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    puts(solve(0, 0) ? "YES" : "NO");
    return 0;
}