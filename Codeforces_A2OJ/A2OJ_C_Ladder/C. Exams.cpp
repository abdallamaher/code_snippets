#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int OO = (int)1e9;
const int N = 1e5 + 5;
 
int n, m, a, b,  f;
pair<int, int> ar[N];
int ans[N];
 
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        ar[i] = {a, b};
    }
    sort(ar, ar + n);
    for(int i=0; i<n; i++){
        if(ar[i].second < ar[i].first && ar[i].second >= ans[i]) {
            ans[i+1] = ar[i].second;
        } else ans[i+1] = ar[i].first;
    }
 
    printf("%d", ans[n]);
    return 0;
}
 
 
 
 
 
 
 