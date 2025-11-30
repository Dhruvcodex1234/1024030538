#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u,v,w;
};

int findP(int x, vector<int>& p) {
    if(p[x]==x) return x;
    return p[x]=findP(p[x],p);
}

void unite(int a, int b, vector<int>& p, vector<int>& r) {
    a=findP(a,p);
    b=findP(b,p);
    if(a!=b) {
        if(r[a]<r[b]) p[a]=b;
        else if(r[b]<r[a]) p[b]=a;
        else {
            p[b]=a;
            r[a]++;
        }
    }
}

int main() {
    int n=4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){return a.w<b.w;});

    vector<int> p(n), r(n,0);
    for(int i=0;i<n;i++) p[i]=i;

    vector<Edge> mst;
    for(auto e: edges) {
        if(findP(e.u,p)!=findP(e.v,p)) {
            mst.push_back(e);
            unite(e.u,e.v,p,r);
        }
    }

    for(auto e: mst) cout<<e.u<<" "<<e.v<<" "<<e.w<<endl;
}

