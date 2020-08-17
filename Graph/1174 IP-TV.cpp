#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, m, tmp;
const int N = 2e3 + 5;
map<string, int> mp;
int p[N];
struct edge {
	int w;
	int u;
	int v;

	edge(int W, int U, int V):w(W), u(U), v(V) {}

	bool operator<(const edge& a)const {
		return w < a.w;
	}
};
vector<edge> vec;

int find_parent(int n) {
	vector<int> v;
	while (p[n] > 0) {
		v.push_back(n);
		n = p[n];
	}
	for (int i = 0; i < v.size(); i++)p[v[i]] = n;
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

void init() {
	tmp = 1;
	mp.clear();
	vec.clear();
	for (int i = 0; i <= n; i++)p[i] = -1;
}

int city(string& s) {
	int n = 0;
	if (!mp[s]) {
		n = tmp;
		mp[s] = tmp;
		tmp++;
	}
	else n = mp[s];
	return n;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> t; cin.ignore();
	while (t--) {
		cin >> n >> m;
		init();
		while (m--) {
			int u, v, w;
			string s1, s2;
			cin >> s1 >> s2 >> w;
			u = city(s1); v = city(s2);

			vec.push_back(edge(w, u, v));
		}
		sort(vec.begin(), vec.end());
		int sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (Union(vec[i].u, vec[i].v)) {
				sum += vec[i].w;
			}
		}
		printf("%d\n", sum);
		if (t)puts("");
	}


	return 0;
}