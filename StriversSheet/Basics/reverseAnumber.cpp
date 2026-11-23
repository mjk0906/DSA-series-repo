class Solution {
public:
    int reverse(int num) {
        long long x = num ;
        int negative = 1 ;
        if(x<0){
            negative = -1 ;
            x*=-1 ;
        }
        int i = 0 ;
        long long ans = 0 ;
        while(x>0){
            int digit=x%10 ;
            x/=10 ;
            ans = ans*10 + digit ;
        }
        ans = ans*negative ;
        if(ans>INT_MAX || ans<INT_MIN){
            return 0 ;
        }
        return (int)ans ;
    }
};
//easy question daily routine