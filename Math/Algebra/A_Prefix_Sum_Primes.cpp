#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int o = 0, t= 0;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x; scanf("%d", &x);
        if(x==1)o++;
        else ++t;
    }
    
    // odd - odd = even
    // 2 3 5 7 11
    if(o && t)printf("2 1 "), o--, t--;
    while(t--)printf("2 ");
    while(o--)printf("1 ");

    /*
    // get primes solution
    int x = 1e7;
    vector<int>vis(x);
    for(int i=2; i*i<x; i++){
        if(!vis[i]){
            for(int j=i+i; j<x; j+=i)vis[j] = 1;
        }
    }
    vector<int> p;
    p.push_back(0);
    for(int i=2; i<x; i++){
        if(vis[i] == 0)p.push_back(i);
    }
    // start use them
    for(int i=1; o || t; i++){
        int diff = p[i] - p[i-1];
        if(diff/2<=t && diff%2<=o){
            int tt = diff/2;
            t-=tt;
            int oo = diff%2;
            o -=oo;
            while(tt--)printf("2 ");
            while(oo--)printf("1 ");
        }else break;
    }
    while(t--)printf("2 ");
    while(o--)printf("1 ");
    */
	return 0;
}