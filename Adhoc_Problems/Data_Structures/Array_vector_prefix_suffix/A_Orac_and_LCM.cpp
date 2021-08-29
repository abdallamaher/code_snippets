#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e5 + 5;
ll sufix[N], ar[N];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld", ar + i);
    }

    /*
    GCD, LCM and Distributive Property :

    GCD(    LCM(x, y),   LCM (x, z)    ) = LCM(  x, GCD(y, z)  )
    vice versa is also true , 
    lcm(    gcd(x, y), gcd(x, z)       ) = gcd(  x, lcm(y, z)  )
    */
    for (int i = n - 1;i >= 0; i--) {
        sufix[i] = gcd(ar[i], sufix[i + 1]);
    }
    ll g = 0;
    for (int i = 0;i < n - 1; i++) {
        g = gcd(g, lcm(ar[i], sufix[i + 1]));
    }

    cout << g << endl;
}