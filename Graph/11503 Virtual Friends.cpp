#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int p[N];
int t, n, tmp;
map<string, int> mp;

int find_parent(int n) {
	while (p[n] > 0) {
		n = p[n];
	}
	return n;
}

void Union(int u, int v) {
	u = find_parent(u);
	v = find_parent(v);
	if (u == v) {
		printf("%d\n", abs(p[u]));
		return;
	}
	p[u] += p[v];
	p[v] = u;
	printf("%d\n", abs(p[u]));
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		tmp = 1;
		while (n--) {
			string s1, s2;
			int u, v;
			cin >> s1 >> s2;
			if (mp[s1] == 0) {
				u = tmp;
				p[tmp] = -1;
				mp[s1] = tmp;
				tmp++;
			}
			else u = mp[s1];

			if (mp[s2] == 0) {
				v = tmp;
				p[tmp] = -1;
				mp[s2] = tmp;
				tmp++;
			}
			else v = mp[s2];

			Union(u, v);
		}
	}

	return 0;
}