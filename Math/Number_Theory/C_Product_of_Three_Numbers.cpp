#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n; scanf("%d", &n);
    set<int> s;
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            int a = i;
            int b = n / i;
            for (int j = 2; j * j < a; j++) {
                if (a % j == 0) {
                    s.insert(j);
                    s.insert(a / j);
                    s.insert(b);
                    break;
                }
            }

            if (s.size() > 2)break;
            s.clear();

            for (int j = 2; j * j < b; j++) {
                if (b % j == 0) {
                    s.insert(j);
                    s.insert(b / j);
                    s.insert(a);
                    break;
                }
            }

            if (s.size() > 2)break;
            s.clear();
        }
    }
    if (s.size() > 2) {
        puts("YES");
        for (auto it : s)printf("%d ", it);
        cout << '\n';
    }
    else puts("NO");
}

void go() {
    // min devisor of any number is prime
    // factoritation( 1 * prime1 * prime2 ) = 1 prime1 prime2
    int n; scanf("%d", &n);
    set<int> s;
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            s.insert(i);
            n /= i;
            break;
        }
    }
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0 && !s.count(i)) {
            s.insert(i);
            n /= i;
            s.insert(n);
            break;
        }
    }
    if (s.size() < 3 || n == 1)puts("NO");
    else {
        puts("YES");
        for (auto it : s)printf("%d ", it);
        cout << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        go();
    }
    return 0;
}