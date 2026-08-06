class Solution {
  public:
    int findMin(int &n) {
        // code here
        int tens= 0;
        int twos = 0;
        int fives = 0 ;
        int ones = 0;
        
        tens = n/10 ;
        while(n>=10){
            n=n%10;
        }
        fives= n/5 ;
        while(n>=5){
            n=n%5;
        }
        twos= n/2 ;
        while(n>=2){
            n=n%2;
        }
        ones = n ;
        int sum = tens+fives+twos+ones ;
        return sum ;
    }
};