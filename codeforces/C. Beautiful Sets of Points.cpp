#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int OO = (int)1e9;
const int N = 1e5 + 5;
int n , m;
 
int main() {
    cin >> n >> m;
 
 
    printf("%d\n", min(m, n) + 1);
    for(int i=0; i<=min(n, m); ++i){
        printf("%d %d\n", i, min(n, m)-i);
    }
    return 0;
}
 
 