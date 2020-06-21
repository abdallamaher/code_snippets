#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int m, s;
string dpMX[110][1000], dpMN[110][1000];

string mini(int i, int sum) {
    if (!i && !sum)return "";
    if (!i || sum < 0)return "x";

    string& ret = dpMN[i][sum];
    if (ret != "")return ret;

    for (char j = '0'; j <= '9'; j++) {
        if (i == m && j == '0')continue;
        string st = j + mini(i - 1, sum - (j - '0'));
        if (st[1] != 'x')
            return ret = st;
    }
    return ret = "x";
}

string maxi(int i, int sum) {
    if (!i && !sum)return "";
    if (!i || sum < 0)return "x";

    string& ret = dpMX[i][sum];
    if (ret != "")return ret;

    //printf("%d %d\n", i, sum);
    for (char j = '9'; j >= '0'; j--) {
        if (i == m && j == '0')continue;
        string st = j + maxi(i - 1, sum - (j - '0'));
        if (st[1] != 'x')
            return ret = st;
    }
    return ret = "x";
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> s;
    if (m == 1 && !s)return cout << "0 0", 0;

    mini(m, s); 
    if (dpMN[m][s] != "x" && dpMN[m][s] != "")
         printf("%s ", dpMN[m][s].c_str());
    else printf("-1 ");

    maxi(m, s);
    if (dpMX[m][s] != "x" && dpMX[m][s] != "")
         printf("%s ", dpMX[m][s].c_str());
    else printf("-1 ");
    return 0;
}

