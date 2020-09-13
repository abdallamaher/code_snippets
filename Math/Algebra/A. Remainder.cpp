#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	
	int n, x, y;
	int ans = 0;
	scanf("%d %d %d", &n, &x, &y);
	string s; cin >> s;
	int i=s.size()-1;
	y++;
	while (x--) {
		if (s.size() - i == y && s[i] != '1')ans++;
		else if (s.size() - i != y && s[i] == '1')ans++;
		i--;
	}
	printf("%d\n", ans);
	return 0;
}