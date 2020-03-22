#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, k;
int ar[N];

int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);
	if (ar[n - 1] == 1)ar[n - 1] = 2;
	else ar[n - 1] = 1;
	sort(ar, ar + n);
	for (int i = 0; i < n; i++)
		cout << ar[i] << ' ';
	return 0;
}








