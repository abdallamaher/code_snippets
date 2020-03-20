#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int OO = (int)1e9;

ll a, b, ans;

void gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (!b) return;
	ans += a/b;
	gcd(a % b, b);
}

int main() {
	cin.sync_with_stdio(false);
	cin >> a >> b;
	gcd(a, b);
	printf("%lld\n", ans);
	return 0;
}








