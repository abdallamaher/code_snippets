#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 9;
#define ll long long 

int n, m, k;
ll sum, sum2;

ll pw(ll n, ll p) {
	ll res = 1;
	while (p > 0) {
		if (p & 1)
			res = (res * n) % mod;
		p /= 2;
		n = (n * n) % mod;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> n >> m >> k;
	sum2 = n % k + 1ll * n / k * (k - 1);
	if (sum2 >= m)return cout << m, 0;

	int r = m - sum2;
	sum = ((pw(2, r+1) -2 + mod)%mod) * k;
	sum2 -= 1ll * r * (k - 1);
	cout << (sum + sum2) % mod;
	return 0;
}









