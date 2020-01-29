#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e3 + 5;

int n;
int ar[N][N];
pair<ll,ll> table[N][N];
ll sum;
struct Points{
    ll s;
    int r;
    int c;
} p, p2;
vector<Points> v;


bool comp(Points i1, Points i2)
{
    return (i1.s < i2.s);
}


bool ok(int r, int c){
    return r>=0 && r<n && c>=0 && c<n;
}

void Left_Down(int r, int c){
    if(ok(r, c)) {
        sum = sum+ar[r][c];
        Left_Down(r+1, c-1);
    }
    table[r][c].first = sum;
    return ;
}

void Right_Down(int r, int c){
    if(ok(r, c)) {
        sum = sum+ar[r][c];
        Right_Down(r+1, c+1);
    }
    table[r][c].second = sum;
    return ;
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; ++j){
            cin >> ar[i][j];
        }
    }

    for(int i=0; i<n; i++){
        sum = 0;
        Right_Down(0, i);
        sum = 0;
        Right_Down(i, 0);
        sum = 0;
        Left_Down(0, i);
        sum =0;
        Left_Down(i, n-1);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; ++j){
            p.s = table[i][j].first+table[i][j].second-ar[i][j];
            p.c = j+1;
            p.r = i+1;
            v.push_back(p);

        }
    }

    sort(v.begin(), v.end(), comp);
    p = v[v.size()-1];
    for(int i=v.size()-1; i>=0; i--){
        int s1 = p.r+p.c;
        int s2 = v[i].r+v[i].c;
        if((s1%2==0&&s2%2==0) || (s1&1 && s2&1))continue;
        p2 = v[i];
        break;
    }
    printf("%lld\n", p.s + p2.s);
    printf("%d %d %d %d",p.r, p.c, p2.r, p2.c);
    return 0;
}


