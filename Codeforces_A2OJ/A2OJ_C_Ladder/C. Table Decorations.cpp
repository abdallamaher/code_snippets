#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cout<<min(a[0]+a[1],(a[0]+a[1]+a[2])/3);
}