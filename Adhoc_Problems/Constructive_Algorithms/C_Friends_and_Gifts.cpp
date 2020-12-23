#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> data(n + n), found(n + n), perm;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &data[i]);
        found[data[i]]++;
    }
    for (int i = 1; i <= n;i++) {
        if (found[i] == 0)perm.push_back(i);
    }
    for (int i = 1, j = 0; i <= n; i++) {
        //cerr << i << endl;
        if (data[i] == 0 && found[i] == 0) {
            //fprintf(stderr, "%d %d %d %d\n", i, data[i], perm[j], perm[j + 1]);
            if (perm[j] == i)swap(perm[j], perm[j + 1]);
            data[i] = perm[j];
            found[perm[j]]++;
            j++;
        }
    }
    for (int i = 1, j = 0; i <= n; i++) {
        if (data[i] == 0) {
            while (found[perm[j]])j++;
            data[i] = perm[j];
            j++;
        }
    }
    for (int i = 1; i <= n;i++) {
        cout << data[i] << ' ';
    }
}

int main() {
    int n; cin >> n;
    vector<int> data(n + n), got(n + n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &data[i]);
        if (data[i])got[data[i]] = 1;
    }
    unordered_set<int> ss;
    for (int i = 1; i <= n; i++)
        if (!got[i]) {
            ss.insert(i);
        }


    for (int i = 1; i <= n; i++) {
        if (!data[i] && !got[i]) {
            int x = *(ss.begin());
            ss.erase(ss.begin());
            //cerr << i << ' ' << x << endl;
            if (x == i) {
                int y = *(ss.begin());
                ss.erase(ss.begin());
                ss.insert(x);
                x = y;
            }
            data[i] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!data[i]) {
            int x = *(ss.begin());
            ss.erase(ss.begin());
            data[i] = x;
        }
    }

    for (int i = 1; i <= n; i++)printf("%d ", data[i]);
}