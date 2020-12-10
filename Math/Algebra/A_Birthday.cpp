#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    ll types, people, has, nw;
    scanf("%lld %lld %lld %lld", &types, &people, &has, &nw);
    ll need = nw + has;
    ll perOne = (need + people - 1) / people;
    if (perOne * people > types || has + nw > types)return cout << -1, 0;
    cout << perOne;
}