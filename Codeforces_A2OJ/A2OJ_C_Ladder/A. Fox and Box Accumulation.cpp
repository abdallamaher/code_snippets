#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = (int)1e9 + 7;

int n, ans, x;
priority_queue<int> ar[105];
int B[105];

int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> B[i];
    }
    sort(B, B+n);
    for(int i=0; i<n; i++){
        B[i]*=-1;
        ar[i].push(B[i]);
    }
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(ar[j].top() * -1 >= ar[i].size()){
                while(ar[i].size()){
                    ar[j].push(ar[i].top());
                    ar[i].pop();
                }
                break;
            }
        }
    }
    for(int i=0; i<n; ++i){
        if(ar[i].size())ans++;
    }
    printf("%d", ans);
    return 0;
}









