#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, vector<vector<int>>& g, int n) {
    vector<int> vis(n,0);
    queue<int> q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v: g[u]) {
            if(!vis[v]) {
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n=5;
    vector<vector<int>> g(n);
    g[0]={1,2};
    g[1]={0,3};
    g[2]={0,4};
    g[3]={1};
    g[4]={2};

    bfs(0,g,n);
}

