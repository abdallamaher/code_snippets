#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 25e4 + 5;
const int mod = (int)1e9 + 7;

int main()
{
    cin.sync_with_stdio(false);
    int n; cin >> n;
    double j = 0; int j2 = 0;
    for(int i=0; i<N; i++){
        j = (n-(4*i)) / (7*1.0);
        j2 = (int)j;
        if(j2==j && j>=0) {
            for(int a=0; a<i; ++a) printf("4");
            for(int a=0; a<j2; ++a) printf("7");
            return 0;
        }
    }
    puts("-1");
    return 0;
}


