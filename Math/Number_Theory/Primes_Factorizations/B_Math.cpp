#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> v;
int mn_res = 1;

void prime_fact(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i)continue;
        mn_res *= i;
        int cnt = 0;
        while (n % i == 0)cnt++, n /= i;
        v.push_back(cnt);
    }
    if (n > 1)mn_res *= n, v.push_back(1);
}

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1 0\n";
        return 0;
    }

    prime_fact(n);
    sort(v.begin(), v.end());
    int mn_steps = 0;
    while ((1 << mn_steps) < v.back())
        mn_steps++;
    cout << mn_res << ' ' << mn_steps + (v[0] != (1 << mn_steps)) << endl;
}