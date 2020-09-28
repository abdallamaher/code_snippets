#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> inp(n);
        for(auto &it: inp)cin >> it;

        vector<int> v(inp);
        sort(v.begin(), v.end());
        
        map<int,int> mp;
        int half = 0;
        for(int i=0; i<n; i++){
            if(v[i] > k/2)break;
            if(k%2==0 && v[i] == k/2){
                half++;
                continue;
            }
            int x = k-v[i];
            mp[x] = 1;
            
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(k%2==0 && inp[i] == k/2){
                if(cnt < half/2)cout << "1 ", cnt++;
                else cout << "0 ";
            }
            else if(mp[inp[i]])cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    
	return 0;
}