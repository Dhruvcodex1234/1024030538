#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n=5;
    int g[5][5] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    vector<int> key(n,INT_MAX), vis(n,0), parent(n,-1);
    key[0]=0;

    for(int i=0;i<n-1;i++) {
        int u=-1;
        for(int j=0;j<n;j++) {
            if(!vis[j] && (u==-1 || key[j]<key[u])) u=j;
        }
        vis[u]=1;
        for(int v=0;v<n;v++) {
            if(g[u][v] && !vis[v] && g[u][v]<key[v]) {
                key[v]=g[u][v];
                parent[v]=u;
            }
        }
    }

    for(int i=1;i<n;i++) cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
}

