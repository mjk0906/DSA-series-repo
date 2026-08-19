class Solution {
public:
    bool dfs(int curr,vector<vector<int>>&graph,vector<int>&states){
        //currently visiting (cycle exists)
        if(states[curr]==1) return false ;
        //safe nodes (so no need to mark false)
        if(states[curr]==2) return true ;
        //node is part of a cycle(so it will lead to a terminal node,mark unsafe)
        if(states[curr]==3) return false ;

        states[curr]= 1 ;
        for(auto v : graph[curr]){
            if(!dfs(v,graph,states)){
                states[curr]= 3 ;
                return false ;
            }
        }

        states[curr]=2 ;
        return true ;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;

        vector<int> states(n,0) ;
        vector<int> ans ;
        for(int i=0;i<n;i++){
            if(dfs(i,graph,states)){
                ans.push_back(i) ;
            }
        }
        return ans ;
    }
};

//very sexy approach , do revise
