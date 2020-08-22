#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
map<char, int> mp;
int h1, h2, h3, p1, p2, p3;
ll r;

bool can(ll x) {
	ll n1 = (x*mp['B'] - h1) * p1; 
	n1 < 0 ? n1 = 0 : 0;

	ll n2 = (x*mp['S'] - h2) * p2; 
	n2 < 0 ? n2 = 0 : 0;

	ll n3 = (x*mp['C'] - h3) * p3; 
	n3 < 0 ? n3 = 0 : 0;

	return r >= n1 + n2 + n3;
}

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	cin >> s;
	for (auto it : s)mp[it]++;

	scanf("%d %d %d %d %d %d %lld", &h1, &h2, &h3, &p1, &p2, &p3, &r);

	ll st = 0, en = 1e14, mid;
	while (st < en) {
		mid = (st + en + 1) >> 1;
		if (can(mid)) 
			st = mid;
		else 
			en = mid - 1;
	}
	printf("%lld\n", en);
	return 0;
}
