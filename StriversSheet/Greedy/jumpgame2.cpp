class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0 ;
        int farthest = 0 ;
        int n = nums.size();
        int currMax = 0 ;
        if(n==1){
            return 0 ;
        }
        for(int i=0;i<n;i++){

            farthest=max(farthest,i+nums[i]);

            if(i==currMax){
                jumps++;
                currMax = farthest ;

                if(currMax>=n-1){
                    break;
                }
            }
        }
        return jumps ;
    }
};
//tricky and good problem