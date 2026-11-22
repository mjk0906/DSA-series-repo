class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "" ;
        ans.reserve(s.size()) ;
        int count = 0 ;
        for(auto x : s){
            if(x=='('){
                if(count>0){
                    ans+=x ;
                }
                count++ ;
            }else{
                count-- ;
                if(count>0){
                    ans+=x ;
                }
            }
        }
        return ans ;
    }
};
//important problem, very very very simple solution but it is important
//reserve command makes sure that suffiecient space is allotted at the start itself
//no further time foes to allot space in the array