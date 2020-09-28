#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
	int t;
	cin >> t;
	while (t--) {
        int n;
		cin >> n;
		int ans = 1e9;
		for (int i = 1; i*i<=n; i++) {
			ans = min(ans, i - 1 + (int)ceil(1.0 * (n - i) / i));
		}
		cout << ans << endl;
	}

	return 0;
}