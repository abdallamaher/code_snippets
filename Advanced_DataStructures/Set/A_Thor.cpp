#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5 + 5;


int n, q, idx, lst;
set<int> mp_unread[N];
set<pair<int, int>> unread;     // mp_unread is enough but set for printing fast
vector<int> Data;

int main() {
    cin >> n >> q;
    while (q--) {
        int t, a; scanf("%d%d", &t, &a);
        if (t == 1) {
            mp_unread[a].insert(idx);
            unread.insert({ idx, a });
            Data.push_back(a);
            idx++;
        }
        else if (t == 2) {
            while (mp_unread[a].size()) {
                auto it = mp_unread[a].begin();
                mp_unread[a].erase(it);
                unread.erase({ *it, a });
            }
        }
        else if (t == 3) {
            if (a > lst) {
                for (int i = lst; i < a; i++) {
                    mp_unread[Data[i]].erase(i);
                    unread.erase({ i, Data[i] });
                }
                lst = a;
            }
        }

        printf("%d\n", unread.size());
    }
}