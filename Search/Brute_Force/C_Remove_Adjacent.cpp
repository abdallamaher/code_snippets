#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
int n;

int main() {
    cin >> n >> s;
    for (char i = 'z'; i > 'a'; i--) {
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == i &&
                (s[j] == s[j + 1] + 1 || s[j] == s[j - 1] + 1)
                ) {
                s.erase(j, 1);
                j--;
            }
        }
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == i &&
                (s[j] == s[j + 1] + 1 || s[j] == s[j - 1] + 1)
                ) {
                s.erase(j, 1);
            }
        }
    }
    cout << n - s.size() << endl;
}