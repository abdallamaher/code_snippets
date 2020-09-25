#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s; cin >> s;
    int r = 0;
    for(int i=0; s[i]; i++){
        r = (r * 10 + (s[i] - '0')) % 4;
    }
    printf("%d\n", int(pow(1, r) + pow(2, r) + pow(3, r) + pow(4, r)) % 5);
    return 0;
}