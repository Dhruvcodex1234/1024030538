#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int u, vector<vector<int>>& g, vector<int>& vis) {
    vis[u]=1;
    cout<<u<<" ";
    for(int v: g[u]) {
        if(!vis[v]) dfsUtil(v,g,vis);
    }
}

void dfs(int start, vector<vector<int>>& g, int n) {
    vector<int> vis(n,0);
    dfsUtil(start,g,vis);
}

int main() {
    int n=5;
    vector<vector<int>> g(n);
    g[0]={1,2};
    g[1]={0,3};
    g[2]={0,4};
    g[3]={1};
    g[4]={2};

    dfs(0,g,n);
}

