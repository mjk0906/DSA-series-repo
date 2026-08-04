class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives,tens,fifteens ;
        fives = 0 ;
        tens = 0 ;
        fifteens = 0;
        for(int i =0;i<bills.size();i++){
            if(bills[i]==5){
                fives++;
            }else if(bills[i]==10){
                tens++;
                if(fives<=0){
                    return false ;
                }
                fives--;
            }else{
                fifteens++;
                if(tens>0 && fives>0){
                    tens--;
                    fives--;
                }
                else if(tens<=0 && fives>=3){
                    fives-=3 ;
                }else{
                    return false ;
                }
            }
        }
        return true ;
    }
};

//easy, leetcode solution