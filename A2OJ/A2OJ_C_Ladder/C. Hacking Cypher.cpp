#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;

string s;
int a , b;
ll ModA, ModB[N];

ll PW_E(ll n, unsigned int p){
    if(p==0) return 1;
    else if(p%2 == 0) return PW_E((n*n)%b, p/2);
    else return (n*PW_E((n*n)%b, (p-1)/2))%b;
}


int main()
{
    cin >> s >> a >> b;
    for(int i=s.size()-1, n=0; i>0; --i, ++n){
        ModB[i] = (ModB[i+1] + ( PW_E(1ll*10, n) * (s[i]-'0') )%b )%b;
    }
    for(int i=0; i<s.size()-1; ++i){
            ModA = ( 1ll*ModA*10 + (s[i]-'0') )%a;
            if(!ModA && !ModB[i+1] && s[i+1] != '0'){
                puts("YES");
                for(int j=0; j<s.size(); ++j){
                    cout << s[j];
                    if(j==i)cout << "\n";
                }
                return 0;
            }
    }
    puts("NO");
    return 0;
}
