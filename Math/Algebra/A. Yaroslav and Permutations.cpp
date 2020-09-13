#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	
	int n;
	scanf("%d", &n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		mp[x]++;
	}
	int sum = 0, mx = 0;
	for (auto it : mp) {
		if (it.second > mx) {
			sum += mx;
			mx = it.second;
		}
		else sum += it.second;
	}
	cerr << mx << ' ' << sum << endl;
	puts(mx - sum > 1 ? "NO" : "YES");
    //other solution: if(mx > (n + 1) / 2)puts("NO"); else finialy puts("yes");
	return 0;
}
