#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    n++;
    printf("%d\n", 3 * n + 1);
    printf("0 0\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i + 1, i);
        printf("%d %d\n", i, i + 1);
        printf("%d %d\n", i + 1, i + 1);
    }
    return 0;
}