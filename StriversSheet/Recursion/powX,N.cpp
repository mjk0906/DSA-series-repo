class Solution {
public:
    double solve(double x,long long power){
        if(power==0){
            return 1.0 ;
        }
        double half = solve(x , power/2) ;
        double result = half * half ;
        if(power%2!=0){
            return x*result ;
        }
        return result ;
    }
    double myPow(double x, int n) {
        long long power = n ;
        if(power<0){
            power = power*(-1) ;
            return 1 / solve(x, power) ;
        }
        return solve(x,power) ;
    }
};
//easy only but double limit issues will come check with it 
//leetcode pe check karo 
