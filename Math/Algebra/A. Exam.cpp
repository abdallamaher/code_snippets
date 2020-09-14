#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n; scanf("%d", &n);
	vector<int> v;
	int t = n;
	if (t & 1 ^ 1)t--;
	while (t >= 1) {
		v.push_back(t);
		t -= 2;
	}
	t = 4;
	while (t <= n) {
		v.push_back(t);
		t += 2;
	}
	if (n > 3)v.push_back(2);
	printf("%d\n", v.size());
	for (auto it : v)printf("%d ", it);
	return 0;
}
