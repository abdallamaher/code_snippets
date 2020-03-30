#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<ll> d;
bool isPrime(ll n) {
	for (int i = 2; 1ll * i * i <= n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	if (isPrime(n) || n == 1) {
		return cout << "1\n0", 0;
	}
	for (int i = 2; 1ll * i * i <= n; i++) {
		if (n % i == 0 && !isPrime(i)) {
			return printf("1\n%d", i), 0;
		}
		if (n % i == 0) {
			d.push_back(n / i);
		}
	}
	for (int i = d.size() - 1; i >= 0; i--) {
		if (!isPrime(d[i])) {
			return printf("1\n%lld", d[i]), 0;
		}
	}
	puts("2");
	return 0;
}