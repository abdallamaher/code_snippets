#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
    int t, n;
	scanf("%d", &t);
	while (t--) {
		ll z, y, x;
		scanf("%lld %lld %lld", &x , &y, &z);
		ll s = z  + z * y; // all needed s
		ll o = (s + x - 3) / (x - 1); // operation to get 
		printf("%lld\n", o + z);
	}
	return 0;
}