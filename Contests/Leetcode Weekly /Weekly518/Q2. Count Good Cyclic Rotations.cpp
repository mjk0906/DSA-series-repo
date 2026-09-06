class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size() ;
        int half = n/2 ;
        long long totalSum = 0 ;
        for(int x : nums){
            totalSum+=x ;
        }
        long long halfSum = 0 ;
        for(int i=0 ;i<half;i++){
            halfSum+=nums[i] ;
        }
        int ans = 0 ;
        for(int i=0 ;i<n ;i++){
            if(halfSum> totalSum-halfSum){
                ans ++ ;
            }
            halfSum-=nums[i] ;
            halfSum+=nums[(i+half)%n] ;
        }
        return ans ;
    }
};

//good tricky interesting string question
//sliding window problem 
