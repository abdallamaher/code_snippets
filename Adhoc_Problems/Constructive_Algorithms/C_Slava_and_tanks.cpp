#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> ans;

int main() {
    cin >> n;
    for(int i=2; i<=n; i+=2)ans.push_back(i);
    for(int i=1; i<=n; i+=2)ans.push_back(i);
    for(int i=2; i<=n; i+=2)ans.push_back(i);

    cout << ans.size() << endl;
    for (auto it : ans)printf("%d ", it);
}