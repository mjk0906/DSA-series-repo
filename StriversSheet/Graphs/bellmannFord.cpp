class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8) ; //distance of every possible vertex from the source node
        dist[src] = 0 ;
        for(int i=0 ; i<V-1 ;i++){
            bool changed = false ;
            for(auto edge : edges){
                int u = edge[0] ;
                int v = edge[1] ;
                int wt = edge[2] ;
                if(dist[u]!=1e8 && dist[v]>dist[u]+wt){
                    dist[v] = dist[u] + wt ;
                    changed = true ;
                }
            }
            if(changed==false){
                break ;
            }
        }
        for(auto edge : edges){
            int u = edge[0] ;
            int v = edge[1] ;
            int wt = edge[2] ;
            if(dist[u]!=1e8 && dist[v]>dist[u]+wt){
                return {-1} ;
            }
        }
        return dist ;
    }
};

//this Algo is used to find the shortest distance from a source vertex to all the nodes in the graph
// when the weight in the graphs can be negative also < Dijkstras does not work