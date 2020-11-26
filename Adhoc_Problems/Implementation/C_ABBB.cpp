#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		string ans;
		for (auto c : s) {
			if (c == 'B' && ans.size() && (ans.back() == 'A' || ans.back() == 'B')) {
				ans.pop_back();
			}
			else ans.push_back(c);
		}
		cout << ans.size() << '\n';
	}
	return 0;
}