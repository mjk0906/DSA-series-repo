class Solution {
public:
    set<vector<int>> s ; //used mainly for the find command
    void helper(vector<int>& arr,int i,vector<int>& current,vector<vector<int>>& ans ,int target){
        if(i>=arr.size() || target<0){
            return ;
        }else if(target == 0){
            if(s.find(current)==s.end()){
                s.insert(current) ;
                ans.push_back(current) ;
                return ;
            }
        }
        current.push_back(arr[i]); //include the element done (base command of inclusion not a call for rest)
        helper(arr,i,current,ans,target - arr[i]) ; // include the same element multiple times ,call for rest
        current.pop_back() ; //  done now remove the present element
        helper(arr,i+1,current,ans,target) ; //  call for rest for the not including present element case
    }
    vector<vector<int>> combinationSum(vector<int>&arr, int target) {
        vector<vector<int>> ans ;
        vector<int> current ;
        helper(arr,0,current,ans,target) ;
        return ans ;
    }
};
//one more important problem, if concept understood done