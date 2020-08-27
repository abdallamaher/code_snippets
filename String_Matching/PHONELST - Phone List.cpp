#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> v;
vector<bool> e;

void insert(string& s) {
	int cur = 0;
	for (int i = 0; i < s.size(); ++i) {
		int c = s[i] - '0';
		if (v[cur][c] == -1) {
			v[cur][c] = v.size();
			v.push_back(vector<int>(10, -1));
			e.push_back(false);
		}
		cur = v[cur][c];
	}
	e[cur] = true;
}


bool find(string& s) {
	int cur = 0;
	for (int i = 0; i < s.size(); ++i) {
		int c = s[i] - '0';
		if (v[cur][c] == -1) {
			return false;
		}
		cur = v[cur][c];
	}
	// return e[cur]; if find word
	return true; // find prefix
}

void init() {
	v.clear();
	e.clear();
	v.resize(1);
	v[0].resize(10, -1);
	e.push_back(false);
}

int main() {
#ifdef LOCAL   
freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while (t--) {
		init();
		int n; scanf("%d", &n);
		vector<string> vec;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			vec.push_back(s);
		}
		sort(vec.rbegin(), vec.rend());
		int f = 0;
		for(int i=0; i<n; i++){
			if (find(vec[i])) {
				puts("NO");
				f = 1;
				break;
			}
			insert(vec[i]);
		}
		if(!f)puts("YES");
		
	}
	return 0;
}
