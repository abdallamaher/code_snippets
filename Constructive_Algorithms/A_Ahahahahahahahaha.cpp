#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
	int t; cin >> t;
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> v;
		v.push_back(0);
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			if (x)v.push_back(i);
		}
		if (v.size() & 1 ^ 1) {
			v.pop_back();
			v.push_back(n);
		}
		else v.push_back(n + 1);
		vector<int> ans;
		for (int i = 1; i < v.size(); i++) {
			int x = v[i] - v[i - 1] - 1;
			if (x & 1 && i < v.size() - 1)x--;
			while (x > 0)ans.push_back(0), x--;
			if (i < v.size() - 1)ans.push_back(1);
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
		}
	}
	return 0;
}