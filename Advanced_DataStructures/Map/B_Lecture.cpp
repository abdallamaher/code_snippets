#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
inline void solve() {
    map<string, string> lang_1;
    map<string, string> lang_2;
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        string a, b; cin >> a >> b ;

        lang_1[a] = b;  // set key $a with value $b
        lang_2[b] = a;
    }

    for(int i=0; i<n; i++){
        string from_first_lang; cin>> from_first_lang;
        if(lang_2.count(from_first_lang))    // check if exist in first 
        {
            from_first_lang = lang_2[from_first_lang];
        }

        int x = from_first_lang.size();
        int y = lang_1[from_first_lang].size();


        if(y < x) {
            cout << lang_1[from_first_lang] << ' ';
        }
        else {
            cout << from_first_lang << ' ';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}