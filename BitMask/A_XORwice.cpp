#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		int ans = 0;
		for (int i = 0; i <= 30; i++) {
			if (( a>>i & 1) && ( b>>i & 1))ans |= 1<<i;
		}
		cout << (a ^ ans) + (b ^ ans) << '\n';
	}

	return 0;
	while (t--) {
		int a, b; cin >> a >> b;
		cout << (b ^ a) << '\n';
	}
	return 0;
}