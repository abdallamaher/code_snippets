#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)1e5 + 5;
int n, ans, cnt;
pair<int, int> ar[N];
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second;
	}
	sort(ar, ar + n, comp);
	for (int i = 0, j=1; i < n; ) {
		if (ar[i].first < ar[j].first && ar[i].second > ar[j].second) {
			cnt++;
			j++;
		}
		else {
			i+=cnt+1;
			ans += cnt;
			cnt = 0;
			j = i + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}













