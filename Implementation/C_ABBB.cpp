#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (i < s.size() - 1 && (s[i] == 'A' || s[i] == 'B') && s[i + 1] == 'B') {
				s.erase(i, 2);
				if(i)i-=2;
				else i--;
			}
		}
		cout << s.size() << '\n';
	}

	return 0;
}