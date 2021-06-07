#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4;

int n, k;
string ar[N];
set<string> st;
set<vector<string>> stt;

string getString(string a, string b) {
    string res = "";
    for (int i = 0; i < k; i++) {
        if (a[i] != b[i]) {
            string ss = "SET";
            ss.erase(ss.begin() + ss.find(a[i]));
            ss.erase(ss.begin() + ss.find(b[i]));
            res += ss;
        }
        else {
            res += a[i];
        }

    }
    return res;
}


int main() {
    cin >> n >> k;

    for (int i = 0;i < n; i++) {
        cin >> ar[i];
        st.insert(ar[i]);
    }

    for (int i = 0;i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string a = ar[i];
            string b = ar[j];
            string c = getString(a, b);
            if (st.find(c) != st.end()) {
                vector<string> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                sort(v.begin(), v.end());

                stt.insert(v);
            }
        }
    }
    cout << stt.size() << endl;
}