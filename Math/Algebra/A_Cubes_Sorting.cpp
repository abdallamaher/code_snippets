#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> v(n);
		for (auto&it : v)scanf("%d", &it);
		int f = 0;
		for (int i = 1; i < n; i++) {
			if (v[i] >= v[i-1])f = 1;
		}
		puts(f ? "YES" : "NO");
	}

	return 0;
}