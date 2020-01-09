#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9;
int m, R;
string mn , mx;
const int N = 305;
int dp[N][N], vis[N][N];
 
bool can (int l , int s) {
    if(l * 9 < s || (!s && l>1)) return 1;
    return 0;
}
 
string mex(int l, int r){
    mx = "";
    for(int i=0; i<l; ++i){
        if(r > 9) {
            mx += (char)( 9 + '0');
            r -= 9;
        }
        else {
            mx += (char)( r + '0');
            r = 0;
        }
    }
    return mx;
}
 
string men(){
    mn = mx;
    reverse(mn.begin(), mn.end());
    if(mn[0] != '0') return mn;
 
    for(int i=0; i<mn.size(); i++){
//        cout << mn << ' ' << i <<"\n";
        if(!i && mn.size()>1)mn[i] = '1';
        else if(mn[i] != '0'){
            mn[i] = (char)(((int)(mn[i]-'0') - 1) + '0');
            break;
        }
    }
    return mn;
}
 
int main() {
    cin >> m >> R;
    if(can(m, R)) return printf("-1 -1\n"), 0;
    string s = mex(m, R);
    cout << men() << ' ' << s;
    return 0;
}
 