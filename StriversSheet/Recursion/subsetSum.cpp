class Solution {
  public:
    void solve(vector<int>& arr,int currSum,int idx,vector<int>& ans){
        if(idx == arr.size()){
            ans.push_back(currSum) ;
            return ;
        }
        //now include the curr element and call further
        currSum+=arr[idx] ;
        solve(arr,currSum,idx+1,ans);
        
        //do not include and call further
        currSum-=arr[idx] ;
        solve(arr,currSum,idx+1,ans) ;
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans ;
        solve(arr,0,0,ans) ;
        return ans ;
    }
};

//easy problem, if you know how to calculate the powerset then u can easily solve this question