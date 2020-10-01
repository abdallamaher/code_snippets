#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int h, m;
    // scanf("%2d%*1s%2d", &h, &m);
    scanf("%2d:%2d", &h, &m);
    int more;
    cin >> more;
    more += m;
    h += more / 60;
    more %= 60;
    h %= 24;
    printf("%02d:%02d\n", h, more);
    return 0;
}