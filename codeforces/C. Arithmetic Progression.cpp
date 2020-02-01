#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = (int)1e9 + 7;

int n, cnt, f, s;
int ar[N];
map<int, int> mp;
vector<int>v, ans;

int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> ar[i];
        mp[ar[i]]++;
    }
    if(n==1)return puts("-1"), 0;
    if(mp.size() == 1)return printf("1\n%d", ar[0]), 0;
    if(mp.size() < n)return puts("0"), 0;
    sort(ar, ar+n);
    mp.clear();
    for(int i=1; i<n; i++){
        mp[ar[i]-ar[i-1]]++;
    }
    if(mp.size() > 2) return puts("0"), 0;
    if(mp.size()==1 && n>2){
        int v = ar[1]-ar[0];
        printf("2\n%d %d", ar[0]-v, ar[n-1]+v);
        return 0;
    }
    for(auto it: mp){
        if(it.second > 1)cnt++;
    }

    if(cnt>1)return puts("0");
    if(mp.size()==1){
        int vv = ar[1]-ar[0];
        ans.push_back(ar[0]-vv);
        ans.push_back(ar[n-1]+vv);
        vv = (ar[n-1]-ar[0]);
        if(vv%2==0)ans.push_back(ar[0]+vv/2);
        printf("%d\n", ans.size());
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++)printf("%d ", ans[i]);
        return 0;
    }
    for(auto it: mp){
        if(!f)f=it.first;
        else s = it.first;
    }
    if(mp[f]!=1)swap(f, s);
    if(mp[f]==mp[s] && f < s)swap(f, s);
    for(int i=1; i<n; i++){
        if(ar[i]-ar[i-1]==f){
            if(ar[i]-s == ar[i-1]+s)return printf("1\n%d", ar[i]-s), 0;
        }
    }
    puts("0");
    return 0;
}


