#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int sum(int x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main() {
	int k; cin >> k;
	int ans = 0;
	while (k)
		if ( sum(++ans) == 10 )
			k--;
	cout << ans << endl;
	return 0;
}