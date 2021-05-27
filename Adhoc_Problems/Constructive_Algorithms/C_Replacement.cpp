#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, q;
string s;
int total;



int main() {
    cin >> n >> q >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            int j = i;
            while (++j < n && s[j] == '.')total++;
            i = j - 1;
        }
    }

    while (q--) {
        int x; char c;
        scanf("%d %c", &x, &c); x--;

        if (c != '.' && s[x] == '.') {
            if (x && s[x - 1] == '.')total--;
            if (x < n - 1 && s[x + 1] == '.')total--;
        }
        else if (c == '.' && s[x] != '.') {
            if (x && s[x - 1] == '.')total++;
            if (x < n - 1 && s[x + 1] == '.')total++;
        }
        
        printf("%d\n", total);
        s[x] = c;
    }
}