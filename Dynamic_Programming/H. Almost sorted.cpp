#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 1e5 + 5;
int ar[N];

int solve() {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		auto idx = upper_bound(v.begin(), v.end(), ar[i]);

		if (idx == v.end())
			v.push_back(ar[i]);
		else
			*idx = ar[i];
	}
	return v.size();
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int t = solve();
	cerr << t << endl;
	if (t == n)cout << 0;
	else cout << n-1-solve();
	return 0;
}

/*
https://codeforces.com/group/EWY9Ags72z/contest/275155/problem/H

5
1 2 2 3 4
*/