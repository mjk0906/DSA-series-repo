class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n) ;
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];
            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
        }
        vector<long long> reachTime(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>> > pq ;
        reachTime[0]=0 ;
        ways[0]=1 ;
        pq.push({0,0});
        while(pq.size()>0){
            auto curr = pq.top();
            int currNode = curr.second ;
            long long currTime = curr.first ;
            pq.pop();

            if(currTime>reachTime[currNode]){
                continue ;
            }

            for(auto edge : graph[currNode]){
                int v = edge.first ;
                int wt = edge.second ;
                long long newTime = currTime + wt ;
                if(reachTime[v]>newTime){
                    reachTime[v]=newTime ;
                    ways[v]=ways[currNode];
                    pq.push({reachTime[v],v});
                }else if(reachTime[v]==newTime){
                    ways[v] = (ways[v] + ways[currNode]) % (1000000007);
                }
            }
        }
        long long ans = ways[n-1];
        int finalans = ans % 1000000007 ;
        return finalans ;
    }
};

//done, dijkstras itself but in an innovative way