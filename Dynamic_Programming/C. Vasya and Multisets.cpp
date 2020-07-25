#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e2 + 7;
int fr[N];
int dp[N][51][51];
vector<int> pos[N];
int n;
int ar[N];
int solve(int i = 0, int s1 = 0, int s2 = 0) {
	if (max(s1, s2) > 50)return 0;
	if (i > 100)return s1 == s2;

	int&ret = dp[i][s1][s2];
	if (~ret)return ret;
	ret = 0;

	if (fr[i] == 0) 
		return ret = solve(i + 1, s1, s2);

	
	if (fr[i] == 1) {
		ret |= solve(i + 1, s1 + 1, s2);
		ret |= solve(i + 1, s1, s2 + 1);
	}

	if (fr[i] == 2) {
		ret |= solve(i + 1, s1 + 1, s2 + 1);
		ret |= solve(i + 1, s1, s2);
	}

	if (fr[i] > 2) {
		ret |= solve(i + 1, s1 + 1, s2);
		ret |= solve(i + 1, s1, s2 + 1);
		ret |= solve(i + 1, s1, s2);
	}
	return ret;
}

char out[N];
void print(int i, int s1, int s2) {

	if (i > 100)return;

	int ret = dp[i][s1][s2];

	if (fr[i] == 0)
		return print(i + 1, s1, s2);

	if (fr[i] == 1) {
		if (solve(i + 1, s1 + 1, s2) == ret) {
			out[ pos[i][0] ] = 'A';
			return print(i + 1, s1 + 1, s2);
		}
		out[ pos[i][0] ] = 'B';
		return print(i + 1, s1, s2 + 1);
	}

	if (fr[i] == 2) {
		if (solve(i + 1, s1 + 1, s2 + 1) == ret) {
			out[pos[i][0]] = 'A';
			out[pos[i][1]] = 'B';
			return print(i + 1, s1 + 1, s2 + 1);
		}
		out[pos[i][0]] = 'A';
		out[pos[i][1]] = 'A';
		return print(i + 1, s1, s2);
	}

	if (fr[i] > 2) {
		if (solve(i + 1, s1 + 1, s2) == ret) {
			out[pos[i][0]] = 'A';
			for (int x = 1; x < pos[i].size(); ++x) {
				out[pos[i][x]] = 'B';
			}
			return print(i + 1, s1 + 1, s2);
		}
		if (solve(i + 1, s1, s2 + 1) == ret) {
			out[pos[i][0]] = 'B';
			for (int x = 1; x < pos[i].size(); ++x) {
				out[pos[i][x]] = 'A';
			}
			return print(i + 1, s1, s2 + 1);
		}
		for (int x = 0; x < pos[i].size(); ++x) {
			out[pos[i][x]] = 'A';
		}
		return print(i + 1, s1, s2);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		fr[ar[i]]++;
		pos[ar[i]].push_back(i);
	}
	memset(dp, -1, sizeof(dp));
	cerr << solve(0, 0, 0) << "\n";

	if (solve(0, 0, 0) == 1) {
		cout << "YES\n";
		print(0, 0, 0);
		for (auto it : out) {
			if (it)cout << it;
		}
		
	}
	else
		cout << "NO";
	return 0;
}