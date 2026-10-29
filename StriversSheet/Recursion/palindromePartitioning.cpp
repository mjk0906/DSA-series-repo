class Solution {
public:
    bool isPal(string s){
        string s2 = s ;
        reverse(s2.begin(),s2.end());
        return s2 == s;
    }
    void helper(string s,vector<vector<string>>&ans,vector<string>&partitions){
        if(s.size()==0){
            ans.push_back(partitions) ;
            return ;
        }
        for(int i=0;i<s.size();i++){
            string part = s.substr(0,i+1) ;
            if(isPal(part)){
                partitions.push_back(part) ;
                helper(s.substr(i+1),ans,partitions) ;
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ;
        vector<string> partitions ;
        helper(s,ans,partitions);
        return ans ;
    }
};

//we have n-1 slots to do partition which means we have choices of 2^n-1 and then worst case whole string will be a palindrome then we have to check for n times(the isPal check) so TC = O(n*2^n) {ignoring constants}
//very interesting problem, write notes