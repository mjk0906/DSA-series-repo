class Solution {
public:
    void add(vector<string>& ans,string s,int open, int close,int n){
        if(s.size()==2*n){
            ans.push_back(s) ;
            return ;
        }
        if(open < n){
            add(ans,s+'(',open+1,close,n) ;
        }
        if(close < open){
            add(ans,s+')',open,close+1,n) ;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        add(ans,"",0,0,n) ;
        return ans ;
    }
};
//okay guys easy problem itself but logic must the understood, for every open u again explore all the possible cases of brackets