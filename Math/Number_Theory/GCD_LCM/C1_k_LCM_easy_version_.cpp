#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
inline void solve() {
	int n, k; scanf("%d %d", &n, &k);
    while(k-- > 3){
        n--;
        printf("1 ");
    }
    
    // odd number so remender by    2     is   1
    if(n & 1){
        // 1/2              1/2            remender(1)
        printf("%d %d 1\n", n/2, n/2);
        return ;
    }


    // even number so remender by    4     is   0, 2
    if(n % 4 == 0){
        // 1/4              1/4            1/4 + 1/4 + remender(0)
        printf("%d %d %d\n", n/4, n/4, n/2);
    }else {
        // 1/4 + 1/4      1/4 + 1/4          remender(2)
        printf("%d %d 2\n", n/2-1, n/2-1);
    }

    // all even and mx = 1/2   so lcm is 1/2

}
 
int main() {
    int t; cin >> t;
    while (t--)solve();
}