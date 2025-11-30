#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int v,w;
};

int main() {
    int n=5;
    vector<vector<Node>> g(n);
    g[0]={{1,2},{2,4}};
    g[1]={{2,1},{3,7}};
    g[2]={{4,3}};
    g[3]={{4,1}};
    g[4]={{3,2}};

    vector<int> dist(n,1e9);
    dist[0]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()) {
        auto t=pq.top();
        pq.pop();
        int u=t.second, d=t.first;
        if(d!=dist[u]) continue;
        for(auto x: g[u]) {
            if(dist[u]+x.w < dist[x.v]) {
                dist[x.v] = dist[u]+x.w;
                pq.push({dist[x.v], x.v});
            }
        }
    }

    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
}

