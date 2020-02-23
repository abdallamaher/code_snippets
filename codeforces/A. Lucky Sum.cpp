#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
const int N = (int)2e5 + 5;

ll l, r, sum;
int st, en;
vector<string> v;

void solve(string st = "") {
	if (st.size() == 11) return;
	st += "4";
	v.push_back(st);
	solve(st);
	st.pop_back();
	st += "7";
	v.push_back(st);
	solve(st);
}

int main() {
	cin.sync_with_stdio(false);
	solve();
	cin >> l >> r;
	vector<ll> lucky(v.size());

	for (ll i = 0; i < v.size(); i++) {
		lucky[i] = 0;
		for (int j = 0; j < v[i].size(); j++) {
			lucky[i] = lucky[i] * 10 + (v[i][j] - '0');
		}
	}

	sort(lucky.begin(), lucky.end());

	st = lower_bound(lucky.begin(), lucky.end(), l) - lucky.begin();
	en = lower_bound(lucky.begin(), lucky.end(), r) - lucky.begin();
	sum = lucky[st];
	for (int i = st; i <= en; i++) {
		ll cnt = 0;
		lucky[i] <= r ? cnt = lucky[i] - l : cnt = r-l;
		sum += lucky[i] * cnt;
		l = lucky[i];
		// printf("%lld\n", cnt);
	}
	printf("%lld", sum);
	return 0;
}

