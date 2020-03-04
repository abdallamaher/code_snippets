#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

string s;
vector<int> l, r;
int main() {
	cin.sync_with_stdio(false);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'l')l.push_back(i + 1);
		else r.push_back(i + 1);
	}
	for (auto it : r) {
		printf("%d\n", it);
	}
	for (int i = l.size() - 1; i >= 0; i--) {
		printf("%d\n", l[i]);
	}
	return 0;
}








