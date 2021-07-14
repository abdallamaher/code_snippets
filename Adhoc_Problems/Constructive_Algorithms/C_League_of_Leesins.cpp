#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
map<int, int> mp;
map<pair<int, int>, vector<int>> Data;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ar[3] = {};
        for (int j = 0; j < 3; j++)scanf("%d", ar + j);
        mp[ar[1]]++, mp[ar[0]]++, mp[ar[2]]++;

        sort(ar, ar + 3);
        Data[{ ar[0], ar[1] }].push_back(ar[2]);
        Data[{ ar[0], ar[2] }].push_back(ar[1]);
        Data[{ar[1], ar[2] }].push_back(ar[0]);
    }

    int fir = -1, sec = -1;
    for (auto it : mp) {
        if (it.second == 1)fir = it.first;
    }
    for (auto it : mp) {
        if (it.second == 2) {
            int x = it.first;
            int y = fir;

            if (x > y)swap(x, y);

            if (Data.count({ x, y })) {
                sec = it.first;
                break;
            }
        }
    }

    printf("%d %d ", fir, sec);

    int thr = -1;
    for (int i = 2; i < n; i++) {
        int x = fir;
        int y = sec;
        if (x > y)swap(x, y);
        vector<int>& v = Data[{x, y}];
        for (auto it : v) {
            if (it != thr) {
                thr = it;
                break;
            }
        }
        printf("%d ", thr);

        int tmp = fir;
        fir = sec;
        sec = thr;
        thr = tmp;
    }
}