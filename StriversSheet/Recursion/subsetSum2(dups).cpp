class Solution {
public:
    void getallsubsets(vector<int>&nums , vector<int>&ans , vector<vector<int>>&allsubsets , int i){
        if (i==nums.size()){
            allsubsets.push_back({ans});
            return ;
        }
        ans.push_back(nums[i]);
        getallsubsets(nums,ans,allsubsets,i+1);
        ans.pop_back() ;
        int idx = i+1 ;
        while (idx<nums.size() && nums[idx]==nums[idx-1]) idx++ ; //main excluding logical step here 3
        getallsubsets(nums,ans,allsubsets,idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<int> ans ;
        vector<vector<int>> allsubsets ;
        getallsubsets(nums,ans,allsubsets,0);
        return allsubsets ;

    }
};
//this problem has a single step of moving the index value to the position such that when we skip a value, we dont include it again through its duplicate
//basically skip all the duplicates of a value if that value is excluded