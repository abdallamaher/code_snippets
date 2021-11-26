#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(int n) {
    for (int i = 2; 1ll * i * i <= n; i++) {
        if (n % i == 0)return 0;
    }
    return 1;
}

int main() {
    int n; cin >> n;
    int ans = 0;

    if (isPrime(n))ans = 1;
    else if (n % 2 == 0)ans = 2;        // evenNumber = sum of 2 primes
    else if (isPrime(n - 2))ans = 2;    // oddNumber = sum of 2 primes    if (n-2) is prime
    else ans = 3;                       // oddNumber = sum of 3 primes     n = 3 + evenNumber

    cout << ans;
}