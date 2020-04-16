#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)1e6 + 7;
int dp[1005][11][11];
int n, ok;
vector<int> v;

int solve(int i, int p, int S1, int S2){
    if(ok) return 0;
    if(i == n) {
        ok = 1;
        return dp[i][p][abs(S1-S2)] = 1;
    }
    if(dp[i][p][abs(S1-S2)]) return dp[i][p][abs(S1-S2)];
    bool ans = 0;
    for(int j=0; j<v.size(); ++j){
        if(v[j]==p)continue;
        if(i%2==0 && S1+v[j]>S2)
            ans = ans | solve(i+1, v[j], S1+v[j], S2);
        if(i%2 && S1<S2+v[j])
            ans = ans | solve(i+1, v[j], S1, S2+v[j]);
    }
    return dp[i][p][abs(S1-S2)] = ans;
}

void dfs(int i, int p, int S1, int S2){
    for(int j=0; j<v.size(); j++){
        if(i%2==0 && dp[i+1][v[j]][abs(S1+v[j]-S2)]){
            printf("%d ", v[j]);
            dfs(i+1, v[j], S1+v[j], S2);
        }
        if(i%2 && dp[i+1][v[j]][abs(S1-S2-v[j])]){
            printf("%d ", v[j]);
            dfs(i+1, v[j], S1, S2+v[j]);
        }
    }
    return ;
}

int main(){
    cin.sync_with_stdio(false);
    string s; cin >> s;
    for(int i=0; i<s.size(); ++i) if(s[i]-'0')
        v.push_back(i+1);
    cin >> n;
    for(int i=0; i<v.size(); i++){
        if(solve(1, v[i], v[i], 0)){
            puts("YES");
            printf("%d ", v[i]);
            dfs(1, v[i], v[i], 0);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
