class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans ; 

        sort(nums.begin(),nums.end());

        for(int i=0 ; i<n ; i++){
            if (i>0 && nums[i]==nums[i-1]){
                continue ;
            }
            int j = i+1 , k = n-1 ;
            while (j<k){
                int sum = nums[i] + nums[j] + nums[k] ;
                if (sum<0){
                    j++ ;
                }
                else if(sum>0){
                    k-- ;
                }
                else if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]}) ;
                    j++ ; k-- ;

                    while(j<k && nums[j]==nums[j-1]){
                        j++ ; //the reason why this loop is written inside the sum found if is because we should not run this loop for every j and k rather we have to run this when we find a solution only because in a sorted array duplicates happen only when a solution is found and running it for every j and k will make us update j and k even when there is no duplicate(How can a duplicate solution exist when the actual solution is itself not found)
                    }
                }
            }
        }
        return ans ;
    }
}; 