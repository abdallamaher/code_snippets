#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int OO = (int)1e9;

int n, k;
string s;

void solve(int i) {
	for (char a = s[i] + 1; a <= 'z' && a - 'a' + 1 <= k; a++) {
		if (a != s[i - 1] && a != s[i - 2]) {
			s[i] = a;
			break;
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin >> n >> k >> s;
	for (int i = n - 1; i >= 0; --i) {
		char t = s[i];
		solve(i);
		if (t != s[i]) {
			for (int j = i + 1; j < s.size(); j++) {
				char F, S;
				F = s[j - 1]; S = s[j - 2];
				if (F != 'a' && S != 'a')s[j] = 'a';
				else if (F != 'b' && S != 'b')s[j] = 'b';
				else if (F != 'c' && S != 'c')s[j] = 'c';
			}
			return printf("%s\n", s.c_str()), 0;
		}
	}
	puts("NO");
	return 0;
}








