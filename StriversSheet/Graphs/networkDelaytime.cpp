class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];
            graph[u].push_back({v,time});
        }
        vector<int> reachTime(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q ;
        reachTime[k]=0 ;
        q.push({0,k});
        while(q.size()>0){
            auto curr = q.top();
            int currNode = curr.second ;
            int currTime = curr.first ;
            q.pop();
            if(currTime>reachTime[currNode]){
                continue ;
            }
            for(auto edge : graph[currNode]){
                int v = edge.first ;
                int wt = edge.second ;
                if(reachTime[v]>currTime+wt){
                    reachTime[v]=currTime+wt ;
                    q.push({reachTime[v],v});
                }
            }
        }
        int ans = 0 ;
        for(int i=1;i<n+1;i++){
            int time = reachTime[i];
            if(time==INT_MAX){
                return -1 ;
            }
            ans=max(ans,time);
        }
        return ans ;
    }
};

//easy but we should know the difference when should we use dijkstras and when to use normal BFS