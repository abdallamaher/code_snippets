#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)2e5 + 5;

int n, cnt;
int x[105], y[105], vis[105];
vector<int> adjList[105];

void BFS(int i){
    vis[i] = cnt;
    queue<int> q;
    q.push(i);
    while(q.size()){
        int v = q.front();
        q.pop();
        for(auto it: adjList[v]){
            if(vis[it])continue;
            vis[it] = cnt;
            q.push(it);
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(x[i]==x[j] || y[i]==y[j]){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            cnt++;
            BFS(i);
        }
    }

    printf("%d\n", cnt-1);
    return 0;
}

