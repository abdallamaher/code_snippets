#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, t;
int ar[1100];
map<vector<int>, bool> solutions;
vector<vector<int>> ans;
void solve(int i, int sum, vector<int> v = {}) {
	if (sum == t) {
		sort(v.begin(), v.end(), [](int a, int b) {
			return a > b;
		});
		if (solutions[v])return;
		solutions[v] = 1;
		ans.push_back(v);
	}
	if (i == n)return;
	solve(i + 1, sum, v);

	v.push_back(ar[i]);
	solve(i + 1, sum + ar[i], v);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> t >> n;
		if (!t && !n)break;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		printf("Sums of %d:\n", t);
		solve(0, 0);
		if (!ans.size()) puts("NONE");
		else {
			sort(ans.rbegin(), ans.rend());
			for (int j = 0; j < ans.size(); j++) {
				vector<int>& v = ans[j];
				for (int i = 0; i < v.size() - 1; i++) {
					printf("%d+", v[i]);
				}
				printf("%d\n", v[v.size() - 1]);
			}
		}
		solutions.clear();
		ans.clear();
	}
	return 0;
}

