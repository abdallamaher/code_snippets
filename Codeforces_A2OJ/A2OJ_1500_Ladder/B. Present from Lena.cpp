#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, l;

void print(int i) {
    int t = n - i;
    while (t--)cout << "  ";
    for (int ii = 0; ii <= i; ii++) {
        if(ii == i && !i)printf("%d", ii);
        else printf("%d ", ii);
    }
    for (int ii = i - 1; ii >= 0; ii--) {
        if (ii == 0)printf("%d", ii);
        else printf("%d ", ii);
    }
    cout << endl;
}
int main() {
    //cin.sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++) {
        print(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        print(i);
    }
    return 0;
}

