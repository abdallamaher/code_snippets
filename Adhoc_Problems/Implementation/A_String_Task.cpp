#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
	string s; cin >> s;
	stringstream ans;
	string vol = "aoyeui";
	for (auto& c : s) {
		c = tolower(c);
		if (vol.find(c) == string::npos) {
			ans << '.';
			ans << c;
		}
	}
	cout << ans.str();
	return 0;
}