#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, q; cin >> n >> q;
    int bad = 0;
    vector<vector<int>> v(4, vector<int>(n + n));
    while (q--) {
        int row, col; scanf("%d %d", &row, &col);
        int before = 0;
        for (int r = 1; r <= 2; r++) {
            for (int c = col - 1; c <= col + 1; c++) {
                before += v[r == 1 ? 2 : 1][c] && bool(v[r][c] || v[r][c - 1] || v[r][c + 1]);
            }
        }
        v[row][col] = 1 - v[row][col];
        int after = 0;
        for (int r = 1; r <= 2; r++) {
            for (int c = col - 1; c <= col + 1; c++) {
                after += v[r == 1 ? 2 : 1][c] && bool(v[r][c] || v[r][c - 1] || v[r][c + 1]);
            }
        }
        bad += after - before;
        puts(!bad ? "Yes" : "No");
    }
}