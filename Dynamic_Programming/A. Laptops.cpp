#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n;
pair<int, int> ar[N];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ar[i] = { a,b };
    }
    sort(ar, ar + n);
    int mn = 1e9; 
    for (int i = n - 1; i >= 0; i--) {
        if (ar[i].second > mn) {
            return puts("Happy Alex"), 0;
        }
        mn = ar[i].second;
    }
    puts("Poor Alex");
    return 0;
}