class Solution {
public:
    string keypad[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    void helper(string& digits,int idx,string curr,vector<string> &ans){
        if(idx==digits.size()){
            ans.push_back(curr) ;
            return ;
        }
        int d = digits[idx] - '0';
        for(int i=0;i<keypad[d].size();i++){
            helper(digits,idx+1,curr+ keypad[d][i],ans) ;
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans ;
        if(digits.empty()){
            return ans ;
        }
        helper(digits,0,"",ans) ;
        return ans ;
    }
};