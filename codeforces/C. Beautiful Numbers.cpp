#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int n, b, a, number;
ll ans;
ll Fact[N];
ll PW(ll n, ll p) {
	if (!p)return 1;
	if (p & 1) return (n * PW((n * n)%mod, p / 2))%mod;
	return PW((n * n) % mod, p / 2)%mod;
}
ll ncr(ll n, ll r) {
	return (Fact[n] * PW(Fact[n - r] * Fact[r] % mod, mod-2)) % mod;
}
void go() {
	Fact[0] = Fact[1] = 1;
	for (int i = 2; i < N; i++) {
		Fact[i] = Fact[i - 1] * i % mod;
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin >> a >> b >> n;
	go();
	for (int i = 0; i <= n; i++) {
		int j = n - i;
		number = i * a + j * b;
		int f = 0;
		while (number) {
			int t = number % 10;
			if (t != a && t != b) {
				f = 1;
				break;
			}
			number /= 10;
		}
		if (!f) {
			// cout << ncr(n, i) << endl;
			ans += ncr(n, i);
			ans %= mod;
		}
	}
	printf("%lld", ans);
	return 0;
}







 