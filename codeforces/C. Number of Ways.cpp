#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int OO = (int)1e9;
const int N = 5 * 1e5 + 5;
 
int n, cnt;
ll ar[N];
ll sum, ans;
 
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%lld", ar + i);
        sum += ar[i];
    }
    if(sum%3 || n<3) return puts("0"), 0;
    sum/=3;
    for(int i=1; i<n; ++i){
        ar[i] += ar[i-1];
    }
 
 
    for(int i=0; i<n-1; ++i){
        if(ar[i] == 2*sum) ans+= cnt;
        if(ar[i] == sum) cnt++;
    }
    printf("%lld\n", ans);
    return 0;
}
 
 
 
 
 
 
 