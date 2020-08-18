#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
struct edge {
	int w; int u; int v;
	edge(int W, int U, int V) : w(W), u(U), v(V) {}
	bool operator<(const edge& a)const {
		return w < a.w;
	}
};
vector<edge> vec;
const int N = 2e5 + 5;
int p[N];

void init() {
	vec.clear();
	for (int i = 0; i <= n; i++)p[i] = -1;
}

int find_parent(int n) {
	vector<int> v;
	while (p[n] >= 0) {
		v.push_back(n);
		n = p[n];
	}

	for (auto it : v)p[it] = n;
	return n;
}


bool Union(int u, int v) {
	u = find_parent(u);
	v = find_parent(v);
	if (u == v)return 0;
	p[u] += p[v];
	p[v] = u;
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &m)) {
		if (n + m == 0)break;
		init();
		int sum = 0;
		while (m--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			vec.push_back(edge(w, u, v));
			sum += w;
		}
		sort(vec.begin(), vec.end());
		int Minsum = 0;
		for (auto it : vec) {
			if (Union(it.u, it.v)) {
				Minsum += it.w;
			}
		}
		printf("%d\n", sum-Minsum);
	}
	return 0;
}













