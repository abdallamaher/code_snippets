#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> v(n + n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int sum = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] > v[i + 1]){
            sum = i + 1;
            break;
        }
    }
    cout << sum << endl;
}