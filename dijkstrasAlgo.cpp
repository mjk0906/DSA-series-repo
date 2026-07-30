#include <iostream>
#include <vector> 
#include <queue>
#include <map>
#include <list> 
#include <stack>
#include <functional>
#include <climits>

using namespace std ;

class Edge{
    public:
        int u ;
        int wt ;

    Edge(int u , int wt){
        this->u = u ;
        this->wt = wt ;
    }
};
void dijkstra(int src ,
    vector<vector<Edge>> g ,int V){
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    pq.push({dist[src],src});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vector<Edge> neighs = g[u];
        for(Edge e : neighs){
            if(dist[e.u]>dist[u]+e.wt){
                dist[e.u]=dist[u]+e.wt ;
                pq.push({dist[e.u],e.u});
            }
        }
    }
    for(int i=0;i<dist.size();i++){
        cout<<i<<"->"<<dist[i]<<"\n";
    }
    cout<<endl ;
}
void bellmannFord(int src,vector<vector<Edge>> g,int V){
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    for(int i=0 ;i<V-1 ;i++){
        for(int u=0; u<V ;u++){
            vector<Edge> neighs = g[u];
            for(Edge e : g[u]){
                if(dist[e.u] >dist[u]+e.wt){
                    dist[e.u] = dist[u]+e.wt ;
                }
            }
        }
    }
    for(int i=0 ;i<V;i++){
        cout<<dist[i] ;
    }
    cout<<endl;
}
int main(){
    int V = 6 ;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));
    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));
    g[2].push_back(Edge(4, 3));
    g[3].push_back(Edge(5, 1));
    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    dijkstra(0,g,6);
    bellmannFord(0,g,6);
}