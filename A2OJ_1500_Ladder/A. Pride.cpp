#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 2e3 + 7;
int ar[N];

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int o = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		if (ar[i] == 1)o++;
	}
	if (o)return cout << n - o, 0;
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		int g = ar[i];
		for (int j = i + 1; j < n; j++) {
			g = gcd(g, ar[j]);
			if (g == 1) {
				ans = min(ans, j - i);
				break;
			}
		}
	}
	if (ans == 1e9)
		cout << -1;
	else 
		cout << n + ans - 1;
	return 0;
}
