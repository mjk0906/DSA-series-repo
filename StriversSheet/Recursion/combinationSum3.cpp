class Solution {
public:
    void solve(vector<vector<int>>&ans,int& k,int& n,vector<int>&curr,int idx){
        if(curr.size()==k && n==0){
            ans.push_back(curr) ;
            return ;
        }
        else if(idx>=10 || n<=0 || curr.size()>=k){
            return ;
        }
        curr.push_back(idx) ; //included the current element
        n-=idx ;
        solve(ans,k,n,curr,idx+1) ;
        curr.pop_back() ;
        n+=idx ;
        solve(ans,k,n,curr,idx+1) ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans ;
        vector<int> curr ;
        solve(ans,k,n,curr,1) ;
        return ans ;
    }
};

//very good problem , learnt how the TC works here, avoid the time of copying a vector, pass by reference
//leetcode problem