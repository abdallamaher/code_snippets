#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n; scanf("%d", &n);
    vector<int> v(n);
    for(int &it: v)scanf("%d", &it);
    int cnt = 1, ans = 1; 
    for(int i=1; i<n; i++) {
        if(v[i] <= v[i-1] * 2) cnt++; 
        else cnt = 1;
        ans = max(cnt, ans);
    }
    printf("%d\n", ans);
    return 0;
}