#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> v(1), sum(1);
ll total = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int a, x; scanf("%d%d", &a, &x);
            sum[a - 1] += x;
            total += 1ll * a * x;
        }
        else if (t == 2) {
            int k; scanf("%d", &k);
            v.push_back(k);
            sum.push_back(0);
            total += k;
        }
        else if (t == 3) {
            total -= v.back() + sum.back();
            sum[sum.size() - 2] += sum.back();  // we are concerned about last element
            v.pop_back();
            sum.pop_back();
        }

        printf("%.6f\n", 1.0 * total / sum.size());
    }
}