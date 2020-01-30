#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e3 + 5;
const int mod = 1000000007;
 
int n, m;
string ar[105];
set<char> s;
ll ans = 1;
 
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    for(int i=0; i<m; i++){
        s.clear();
        for(int j=0; j<n; j++){
            s.insert(ar[j][i]);
        }
        ans = (ans * s.size())%mod;
    }
    cout << ans;
    return 0;
}
 