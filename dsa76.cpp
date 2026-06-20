class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        vector<int> leftM(n,0) ;
        vector<int> rightM(n,0) ;
        leftM[0] = ht[0] ;
        rightM[n-1] = ht[n-1] ;
        for(int i = 1 ; i<n ; i++){
            leftM[i] = max(leftM[i-1],ht[i]) ;
        }
        for(int i=n-2 ; i>=0 ;i--){
            rightM[i] = max(rightM[i+1],ht[i]) ;
        }
        int ans = 0 ;
        int currWater = 0;
        for(int i=0 ; i<n ; i++){
            currWater = min(leftM[i],rightM[i]) - ht[i] ;
            ans+=currWater ;
        }
        return ans ;
    }
};

//this is the code for trapping rain water problem but not the most optimal one (prefix array approach)