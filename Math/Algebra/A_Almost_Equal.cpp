#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
 
int main() {
    int n; scanf("%d", &n);
    if(n&1^1)puts("NO");
    else {
        puts("YES");
        int l = 1, r = 2, f = 1;
        vector<int> ans(2*n);
        for(int i=0;i <n; i++){
            if(f){
                ans[i] = l;
                ans[n + i] = r;
            }else{
                ans[i] = r;
                ans[n + i] = l;
            }
            f^=1; l+=2; r+=2;
        }
        for(auto it: ans)printf("%d ", it);
 
    }
	return 0;
}