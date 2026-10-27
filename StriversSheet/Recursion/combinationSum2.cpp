class Solution {
public:
    void solve(vector<vector<int>>&ans,int curr,int target,vector<int>comb,vector<int>&candidates){
        if(target==0){
            ans.push_back(comb);
            return ;
        }
        else if(curr >= candidates.size()||target<0){
            return ;
        }
        //include the curr element
        comb.push_back(candidates[curr]);
        solve(ans,curr+1,target-candidates[curr],comb,candidates) ;
        //exclude the curr element (so do not include the duplicates also)
        comb.pop_back() ;
        int next = curr+1 ;
        while( next<candidates.size() && candidates[curr]==candidates[next]){
            next++ ;
        }
        solve(ans,next,target,comb,candidates) ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()) ;
        vector<vector<int>> ans ;
        if(candidates.size()==0){
            return ans ;
        }
        solve(ans,0,target,{},candidates) ;
        return ans ;
    }
};
//important variation of combination sum (important)