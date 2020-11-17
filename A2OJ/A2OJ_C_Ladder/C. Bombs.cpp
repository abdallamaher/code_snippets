#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)1e5 + 7;

struct points {
    int x;
    int y;
} point;
int n, ans;
points ar[N];

bool comp(points p1, points p2){
    return abs(p1.x)+abs(p1.y) < abs(p2.x)+abs(p2.y);
}

int main(){
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> ar[i].x >> ar[i].y;
        if(!ar[i].x || !ar[i].y)ans+=4;
        else ans+=6;
    }
    sort(ar, ar+n, comp);
    printf("%d\n", ans);
    for(int i=0; i<n; i++){
        if(ar[i].x)printf("1 %d %c\n",abs(ar[i].x), ar[i].x>0 ? 'R' : 'L');
        if(ar[i].y)printf("1 %d %c\n", abs(ar[i].y), ar[i].y>0 ? 'U' : 'D');
        puts("2");
        if(ar[i].y)printf("1 %d %c\n", abs(ar[i].y), ar[i].y<0 ? 'U' : 'D');
        if(ar[i].x)printf("1 %d %c\n",abs(ar[i].x), ar[i].x<0 ? 'R' : 'L');
        puts("3");
    }
    return 0;
}

