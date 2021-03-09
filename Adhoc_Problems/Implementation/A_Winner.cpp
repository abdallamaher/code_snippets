#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e3 + 4;

int main() {
    int n; cin >> n;
    map<string, int> last;
    string names[N];
    int val[N];
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> val[i];
        last[names[i]] += val[i];
    }
    int mxy = 0;
    vector<string> v;
    for (auto it : last) {
        if (it.second == mxy) {
            v.push_back(it.first);
        }
        else if (it.second > mxy) {
            v.clear();
            v.push_back(it.first);
            mxy = it.second;
        }
    }
    last.clear();
    string ans;
    for (int i = 0; i < n; i++) {
        last[names[i]] += val[i];
        if(last[names[i]] >= mxy && find(v.begin(), v.end(), names[i])!=v.end()){
            ans = names[i];
            break;
        }
    }
    cout << ans << endl;
}