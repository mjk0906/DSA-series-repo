class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp ;
        for(auto curr : nums){
            if(curr%k==0){
                int x = curr/k ;
                mp[x]=curr ;
            }
        }
        int y = 1 ;
        while(true){
            if(mp.find(y)==mp.end()){
                int ans = k*y ;
                return ans ;
            }
            y++ ;
        }
    }
};

//easy question