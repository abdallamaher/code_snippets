#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int n;
pair<int, int> ar[N];
vector<pair<int, int>> ans1, ans2;
int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first;
		ar[i].second = i;
	}


	sort(ar, ar + n);
	for (int i = n-1; i>=0; --i) {
		if (i & 1)ans1.push_back(ar[i]);
		else ans2.push_back(ar[i]);
	}



	int m = ans1.size();
	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
		printf("%d ", ans1[i].second + 1);
	}puts("");
	m = ans2.size();
	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
		printf("%d ", ans2[i].second + 1);
	}
	return 0;
}








 