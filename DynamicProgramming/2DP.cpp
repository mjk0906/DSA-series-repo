//leetcode solution for the problem climbing stairs 70
class Solution {
public:
    int helper(int n,vector<int> & dp){
        if(n==1 || n==2){
            return n ;
        }
        if(dp[n]!=-1){
            return dp[n] ;
        }
        return dp[n] = helper(n-1,dp)+helper(n-2,dp) ;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp) ;
    }
    //tabulation solution
    int climbStairs(int n) {
        if(n==1||n==2) return n ;

        vector<int> dp(n+1) ;
        dp[1] = 1;
        dp[2] = 2 ;
        for(int i=3;i<n+1;i++){
            dp[i] = dp[i-1] + dp[i-2] ;
        }

        return dp[n] ;

    }
    //another version of tabulation here no use of a big vector or table , only 2 variables
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) return n ;
        int prev1 = 1 ;
        int prev2 = 2 ;
        int result = prev2;
        for(int i=3 ; i<n+1 ;i++){
            result = prev1 + prev2 ;
            prev1= prev2 ;
            prev2=result ;
        }
        return result ;
    }
}

};