class Solution {
public:
    long long power(long long exp , long long pos ,long long MOD){
        long long ans = 1 ;
        while(pos>0){
            if(pos%2==1){
                ans = (ans*exp)%MOD;
            }

            exp = (exp*exp)%MOD ;
            pos = pos/2 ;
        }
        return ans ;
    }
    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7 ;
        long long evenPos = n/2 ;
        long long oddPos = (n+1)/2 ;

        long long ans = power(5,oddPos,MOD) * power(4,evenPos,MOD) % MOD ;
        return ans ;
    }
};

//very good problem , lot of binary knowledge basics here
//basically we can use recursion to optimise the structure of the power function in a recursive way