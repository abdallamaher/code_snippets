#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<vector<int>> r(n, vector<int>(m));
		vector<int> v;
		map<int, vector<int>> res;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> r[i][j];
			}
            v.push_back(r[i][0]);
			res[r[i][0]] = r[i];
		}
		vector<vector<int>> c(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> c[i][j];
			}
		}
		vector<int> ans;
		for (int i = 0; i < m; i++) {
			map<int, int> m;
            for(auto it: c[i])m[it]++;
            for(auto it: v)m[it]++;
            int ok = 1;
            for(auto it: m)if(it.second != 2){
                ok = 0;
                break;
            }
            if(ok){
                ans = c[i];
                break;
            }
		}
		for (int i = 0; i < ans.size(); i++) {
			for (auto it : res[ans[i]])cout << it << ' ';
			cout << '\n';
		}
	}

	return 0;
}