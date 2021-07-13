#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

int main() {
    cin >> n;

    int g = 1;
    while (n > 0) {
        if (n == 3) {
            cout << g << " " << g << " " << g * 3;
            return 0;
        }
        for (int i = 0; i < (n + 1) / 2; ++i) {
            cout << g << " ";
        }
        g *= 2;
        n /= 2;
    }
}