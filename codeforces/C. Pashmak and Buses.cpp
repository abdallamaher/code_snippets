#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)1e3 + 5;

int n, k, d, cnt;
vector<int> v;
int ans[N][N];

void solve(int day=0){  // generate permutations subsets
    if(day == d){
            for(int i=0; i<v.size(); ++i){
                ans[cnt][i] = v[i];
            }
            cnt++;
            return ;
    }
    for(int i=1; i<=k; i++){
        v.push_back(i);
        solve(day+1);
        v.pop_back();
        if(cnt == n) return ;
    }
}
int main() {
    cin >> n >> k >> d;
    ll t = 1; int f = 0;
    for(int i=0; i<d; i++){
        t *= k;
        if(t >= n){f=1; break;}
    }
    if(!f) return puts("-1"), 0;
    solve();
    for(int j=0; j<d; j++){
        for(int i=0; i<n; i++)
            printf("%d ", ans[i][j]);
        puts("");
    }
    return 0;
}

