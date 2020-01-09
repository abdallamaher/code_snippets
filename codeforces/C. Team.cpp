#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int OO = (int)1e9;
const int N = 5 * 1e5 + 5;
 
int n, m;
 
int main() {
    scanf("%d %d", &n, &m);
    if(m > 2 * n + 2 || (n > m && n-m != 1)) return puts("-1"), 0;
 
    while(n || m){
//        printf("*******\n");
        if(n > m && m > 0){
            printf("01");
            m--; n--;
        }else if(n == m){
            printf("10");
            m--; n--;
        } else if(n && m > 2){
            printf("110");
            m-=2; --n;
        } else if(n && m){
            printf("10");
            --n;
            --m;
        } else if(n){
            printf("0");
            --n;
        } else if(m){
                printf("1");
                m--;
        }
    }
 
    return 0;
}
 
 
 