#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 205;
int a[N];
int b[N];
int n, m;

inline bool isValid(int x) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        int ok = 0;
        for (int j = 0; j < m; j++) {
            if (x == ((a[i] & b[j]) | x)) {
                ok = 1;
                break;
            }
        }
        res &= ok;
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)scanf("%d", &b[i]);

    for (int i = 0; i < (1 << 9); i++) {
        if (isValid(i)) {
            printf("%d\n", i);
            break;
        }
    }

}