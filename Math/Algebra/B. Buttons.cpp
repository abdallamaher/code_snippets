#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int sum = n;
	int i = 1;
	while(--n){
		i++;
		sum += (n - 1) * i + 1;
	}
	printf("%d\n", sum);
	return 0;
}