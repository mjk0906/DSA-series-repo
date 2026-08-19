class Solution {
  public:
    vector<vector<pair<int,int>>> createGraph(int V,vector<vector<int>>&edges){
        vector<vector<pair<int,int>>> graph(V);
        for(int i=0;i<edges.size();i++){
            vector<int> curr = edges[i];
            int u = curr[0];
            int v = curr[1];
            int wt = curr[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        return graph ;
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> graph = createGraph(V,edges);
        vector<int> dist(V,INT_MAX) ;
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq ;
        
        dist[src] = 0;
        pq.push({dist[src],src}) ;
        while(pq.size()>0){
            int u = pq.top().second ;
            pq.pop();
            
            for(auto &e : graph[u]){
                if(dist[e.first]>dist[u]+e.second){
                    dist[e.first]=dist[u]+e.second ;
                    pq.push({dist[e.first],e.first});
                }
            }
        }
        return dist ;
    }
};

//one of the most famous algos of all time for shortest distance findings