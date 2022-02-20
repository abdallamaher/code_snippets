#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<vector<int>> threeSum(vector<int>& ar) {
    int n = ar.size();
    sort(ar.begin(), ar.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++) {
        if (i && ar[i - 1] == ar[i])continue;
        
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = ar[i] + ar[l] + ar[r];
            if (sum == 0) {
                ans.push_back({ ar[i], ar[l] , ar[r] });
                l++;
                r--;
                while (l < r && ar[l - 1] == ar[l])l++;
                while (l < r && ar[r] == ar[r + 1])r--;
            }
            else if (sum < 0) {
                l++;
            }
            else if (sum > 0) {
                r--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> v = { -1,0,1,2,-1,-4 };
    vector<vector<int>> ans = threeSum(v);
    for (auto& it : ans) {
        for (auto& x : it)cout << x << ' ';
        cout << endl;
    }
}