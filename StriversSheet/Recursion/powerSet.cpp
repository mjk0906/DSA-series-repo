class Solution {
public:
    void add(vector<vector<int>>&ans,vector<int>&nums,vector<int> curr,int i){
        if(i == nums.size()){
            ans.push_back(curr) ;
            return ;
        }
        //have basically only 2 options ,eiher take the element or leave the element at every element
        //take the element
        curr.push_back(nums[i]);
        add(ans,nums,curr,i+1) ;
        //leave the element
        curr.pop_back() ;
        add(ans,nums,curr,i+1) ; //never give i++ in these type of situations
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        add(ans,nums,{},0) ;
        return ans ;
    }
};

//very important problem , do solve it again, important for recursion