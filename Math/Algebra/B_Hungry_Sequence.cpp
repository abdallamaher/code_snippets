#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n;
    scanf("%d", &n);
    /*
    a < b < 2 * a
    (a%b) != 0
    so: 

    for(int i=1000000; i<1000000 + n; i++)printf("%d ", i);
    */

    // generate all prime numbers under (N) ~7e5
    const int N = 1e7 + 1;
    vector<int> ar(N);
    for(int i=2;i*i <N; i++){
        if(!ar[i]){
            for(int j=i+i; j<N; j+=i) ar[j] = 1;
        }
    }
    for(int i=2; n; i++)
        if(!ar[i]) {
            printf("%d ", i); 
            n--;
        }
    return 0;
}