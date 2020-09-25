	#include <bits/stdc++.h>
	using namespace std;
	#define ll long long
	#define ld long double

	int main() {
        int n; scanf("%d", &n);
        int l = 0, r = 0,s = 0;
        while(n--){
            int a,b; scanf("%d%d", &a, &b);
            if(a%2 != b%2)s = 1;
            if(a&1)l++;
            if(b&1)r++;
        }
		if(r%2==0 && l%2==0)puts("0");
        else if(r&1 && l&1) puts(s ? "1" : "-1");
        else puts("-1");
		return 0;
	}