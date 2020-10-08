#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    string ar[] = { "December", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" };
    string s; int n;
    cin >> s >> n;
    auto p = find(ar, ar + 12, s) - ar;
    cout << ar[(p + n) % 12] << endl;
    return 0;
}