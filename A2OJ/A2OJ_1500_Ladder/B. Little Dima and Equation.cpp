#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a, b, c;
vector<int> v; 

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    for (int i = 1; i <= 81; i++) {
        int res = b * pow(i, a) + c;

        int su = 0, t = res;
        while (t) {
            su += t % 10;
            t /= 10;
        }
        if (su == i && res>0 && res<1e9) v.push_back(res); 
    }
    cout << v.size() << endl;
    for (auto it : v)cout << it << ' ';
    return 0;
}
