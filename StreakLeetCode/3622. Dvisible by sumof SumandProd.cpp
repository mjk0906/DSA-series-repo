class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int N = n ;
        while(N>0){
            int rem = N%10 ;
            N=N/10 ;
            sum+=rem ;
            prod*=rem ;
        }
        int x = sum+prod ;
        if(n%x==0) return true;
        return false ;
    }
};
//easy