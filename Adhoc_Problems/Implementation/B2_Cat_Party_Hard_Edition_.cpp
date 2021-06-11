#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int n;
int ocr[N], cnt[N];


int main() {
    cin >> n;
    int ans = 0, mxO = 0;
    for (int i = 1;i <= n; i++) {
        int color; scanf("%d", &color);

        cnt[ocr[color]]--;
        ocr[color]++;
        cnt[ocr[color]]++;

        mxO = max(ocr[color], mxO);

        bool ok = 0;
        if (cnt[1] == i) ok = 1;    // all occur once
        else if (cnt[i] == 1)ok = 1;    // all the same 
        else if (cnt[1] == 1 && cnt[mxO] * mxO == i - 1)ok = 1;     // 1 num occur once   &&    other occur equally
        else if (cnt[mxO] == 1 && cnt[mxO - 1] * (mxO - 1) == i - mxO)ok = 1;   //  1 num occur  once more than other

        if (ok) ans = i;
    }

    cout << ans;
}