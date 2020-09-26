#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    string s; cin >> s;
    int f = 0;
    for(int i=1, p = 0; i < s.size(); ) {
        if(s[i]==s[p]){
            f++;
            s.erase(p, 2);
            if(p)p--, i--;
        }
        else {
            p = i;
            i++;
        }
    }
    puts(f&1 ? "Yes" :"No");
	return 0;
}