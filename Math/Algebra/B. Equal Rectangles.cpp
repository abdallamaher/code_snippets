#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		map<int, int> mp = {};
		vector<int> v;
		for (int i=0; i<n*4; i++) {
			int x; scanf("%d", &x);
			if (!mp[x])v.push_back(x);
			mp[x]++;
		}
		int f = 1, area = 0, cnt = 0;
		sort(v.begin(), v.end());
		for (int i = 0, j = v.size() - 1; i<=j; j--, i++) {
			if (!area) {
				area = v[i] * v[j];
			}
			else {
				f &= bool(v[i] * v[j] == area);
			}
			
			f &= bool(mp[v[i]] == mp[v[j]]);

			if(i!=j)cnt += (mp[v[i]]+mp[v[j]]) / 4;
			else cnt += mp[v[i]] / 4;
		}
		if (cnt != n)f = 0;
		puts(!f ? "NO" : "YES");
		cerr << "****************\n";
	}
	return 0;
}