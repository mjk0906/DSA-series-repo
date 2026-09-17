class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false ;
        int num = x ;
        long long reverse = 0 ;
        while(num>0){
            long long digit = num%10 ;
            num/= 10 ;
            reverse = reverse*10 + digit ;
        }
        return reverse == (long long)x ;
    }
};

//easy hai, no need of stack here, we can use stack here or use 2 pointer approach also here(done)