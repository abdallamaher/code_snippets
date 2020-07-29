#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
int n;
int ar[N];

int LIS() {
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		auto p = lower_bound(v.begin(), v.end(), ar[i]);
		if (p == v.end())
			v.push_back(ar[i]);
		else
			v[p - v.begin()] = ar[i];
	}
	return (int)v.size();
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	cout << LIS();
	return 0;
}

