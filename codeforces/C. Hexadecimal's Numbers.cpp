#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)1e6 + 7;
const int mod = (int)1e9 + 7;

int n, ans = 1;
void solve(int i = 1){
    if(i > n) {
        ans--;
        return ;
    }
    ans+=2;
    solve(i*10+0);
    solve(i*10+1);
}
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    solve();
    printf("%d \n", ans);
    return 0;
}
