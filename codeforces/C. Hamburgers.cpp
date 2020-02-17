#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)2e5 + 5;

string s;
int h1, h2, h3, p1, p2, p3, c1, c2, c3;
ll r;

bool can(ll mid){
    ll n1 = mid * c1 - h1;
    n1 > 0 ? n1 *= p1 : n1 = 0;

    ll n2 = mid * c2 - h2;
    n2 > 0 ? n2 *= p2 : n2 = 0;

    ll n3 = mid * c3 - h3;
    n3 > 0 ? n3 *= p3 : n3 = 0;

    return r >= n1+n2+n3;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> s >> h1 >> h2 >> h3
    >> p1 >> p2 >> p3 >> r;
    for(auto c: s){
        if(c == 'B')c1++;
        else if(c == 'S')c2++;
        else c3++;
    }
    ll st = 0, mid , en = 2e12;
    while(st < en){
        mid = (st + en + 1) / 2;
        if(can(mid))
              st = mid;
        else
              en = mid - 1;
    }
    printf("%lld\n", en);
    return 0;
}

