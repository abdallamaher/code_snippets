#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)2e5 + 5;
 
int n, m, k;
char g[505][505];
int vis[505][505];
int dr[] = {0, -1, 0, 1}, dc[] = {-1, 0, 1, 0};
 
bool ok(int r, int c){
    return r<n && c<m && r>=0 && c>=0 && g[r][c]=='.' && !vis[r][c];
}
 
void dfs(int r, int c){ //DFS topological Order
    vis[r][c]++;
    for(int i=0; i<4; i++){
        int nr=r+dr[i], nc=c+dc[i];
        if(ok(nr, nc)) dfs(nr, nc);
    }
    if(k){
        k--;
        g[r][c] = 'X';
    }
}
 
int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
        }
    }
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && g[i][j]=='.')dfs(i, j);
        }
    }
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << g[i][j];
        }
        puts("");
    }
    return 0;
}