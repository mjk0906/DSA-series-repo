class Solution {
public:
    bool isPalindrome(string s) {
        string newS ;
        for(char x : s){
            if(isalnum(x)){
                newS+=tolower(x) ;
            }
        }
        int i = 0 ;
        int j = newS.size()-1 ;
        bool pal = true ;
        while(i<=j){
            if(newS[i]!=newS[j]){
                pal = false ;
            }
            i++ ;
            j-- ;
        }
        return pal ;
    }
};

//easy problem , learn this approach of two pointer keep in mind 