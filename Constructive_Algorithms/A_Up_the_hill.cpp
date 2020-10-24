#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int a, b; cin >> a >> b;
    int n = a + b + 1;
    while(b > 0){
        cout << n << ' ' ;
        n--;
        b--;
    }
    int j = 1;
    while(a >= 0){
        cout << j << ' ';
        j++;
        a--;
    }
    return 0;
}