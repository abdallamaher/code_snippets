#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	for (auto &it : v) scanf("%d", &it);
	sort(v.begin(), v.end());
	int f = 0;
	for (int i = n - 1; i >= 0; i--) {
		int l = i - 1, r = i + 1;
		if (r >= n)r = 0;
		if (l < 0)l = n - 1;
		if (f && v[i] >= v[l] + v[r])return puts("NO"), 0;
		else if (v[i] >= v[l] + v[r]) {
			f = 1;
			if(i > 0)swap(v[i], v[l]);
			i++;
		}
		else f = 0;
	}
	puts("YES");
	for (int i = 0; i < n; i++)printf("%d ", v[i]);
	return 0;
}
