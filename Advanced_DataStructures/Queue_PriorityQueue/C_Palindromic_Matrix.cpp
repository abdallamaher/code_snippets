#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int ar[30][30];
map<int, int>frq;
priority_queue<pair<int, int>> pq;

void no() {
    puts("no");
    exit(0);
}

void fill(vector<pair<int, int>> v) {
    auto t = pq.top();
    pq.pop();
    if (t.first < v.size()) {
        no();
    }

    for (auto& [i, j] : v) {
        ar[i][j] = t.second;
    }
    t.first -= v.size();
    pq.push(t);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < n; j++) {
            int x; scanf("%d", &x);
            frq[x]++;
        }
    }

    for (auto& [key, value] : frq) {
        pq.push({ value, key });
    }

    int m = n / 2;
    for (int i = 0; i < m;i++) {
        for (int j = 0;j < m;j++) {
            int ii = n - i - 1;
            int jj = n - j - 1;
            fill({ {i, j}, {i, jj}, {ii, j}, {ii, jj} });
        }
    }

    if (n & 1) {
        for (int i = 0;i < m;i++) {
            int ii = n - i - 1;
            fill({ {i, m}, {ii, m} });
            fill({ {m, i}, {m, ii} });
        }

        fill({ {m, m} });
    }

    puts("YES");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ar[i][j] << ' ';
        cout << endl;
    }
}