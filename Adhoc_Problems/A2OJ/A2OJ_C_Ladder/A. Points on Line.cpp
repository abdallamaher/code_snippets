#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, k;
int ar[N];
ll ans;

int main() {
	cin.sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	for (int i = 0; i < n; i++) {
		int l = upper_bound(ar, ar + n, ar[i] + k) - ar - 1;
		l-=i;
		ans += 1ll * l * (l - 1) / 2;	
	}
	printf("%lld\n", ans);
	return 0;
}








