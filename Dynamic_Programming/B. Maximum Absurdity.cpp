#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
const int N = 2e5 + 5;
int ar[N];
ll sum[N];
pair<ll, int> a[N];
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
		sum[i] = sum[i - 1] + ar[i];
	}
	for (int i = n - k; i >= k; i--) {	// 5-2=3    ]3-5]  max not inclusive 3
		ll s = sum[i + k] - sum[i];
		if (s >= a[i + 1].first) {
			a[i] = { s, i + 1 };
		}
		else
			a[i] = a[i + 1];
	}

	pair<int, int> ans; ll mx = 0;
	for (int i = 0; i < n - k; i++) {
		ll s = sum[i + k] - sum[i] + a[i + k].first;
		if (s > mx) {
			ans = { i + 1, a[i + k].second };
			mx = s;
		}
	}
	cout << ans.first << ' ' << ans.second;
	return 0;
}
