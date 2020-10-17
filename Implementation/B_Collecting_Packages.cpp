#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
	int t; cin >> t;
	while (t--) {
		int n; scanf("%d", &n);
		vector<pair<int, int> > v(n);
		for (auto& it : v)scanf("%d %d", &it.first, &it.second);
		v.push_back({ 0, 0 });
		sort(v.begin(), v.end());

		int ok = 1;
		stringstream ans;
		for (int i = 1; i <= n; i++) {
			int x = v[i].first - v[i - 1].first;
			int y = v[i].second - v[i - 1].second;
			if (x < 0 || y < 0) {
				ok = 0;
				break;
			}
			ans << string(x, 'R');
			ans << string(y, 'U');
		}
		if (ok)
			cout << "YES\n" << ans.str() << '\n';
		else cout << "NO\n";
	}
	return 0;
}