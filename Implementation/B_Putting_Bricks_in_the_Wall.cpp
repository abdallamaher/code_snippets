#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
	int t; cin >> t;
	while (t--) {
		int n;  cin >> n;
		vector<string> g;

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			g.push_back(s);
		}
		n--;
		vector<pair<int, int>>v;
		if (g[0][1] == g[1][0]) {
			if (g[n][n - 1] == g[0][1])v.push_back({ n, n - 1 });
			if (g[n - 1][n] == g[0][1])v.push_back({ n - 1, n });
		}
		else {
			char x = g[n][n - 1];
			x = (1 - (x - '0') + '0');
			if (g[0][1] != x)v.push_back({ 0, 1 });
			if (g[1][0] != x)v.push_back({ 1, 0 });
			if (g[n - 1][n] == x)v.push_back({ n - 1, n });
		}

		cout << v.size() << '\n';
		for(auto it: v)printf("%d %d\n", it.first+1, it.second+1);

	}
	return 0;
}