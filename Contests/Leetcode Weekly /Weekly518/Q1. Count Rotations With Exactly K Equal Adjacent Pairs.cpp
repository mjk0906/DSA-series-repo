class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size() ;
        int c = 0 ;
        for(int i=0 ; i<s.size() ;i++){
            if(s[i]==s[(i+1)%n]){
                c++ ;
            }
        }
        if(k==c){
            return n-c ;
        }
        if(k==c-1){
            return c ;
        }
        return 0 ;
    }
};
//tricky 
    