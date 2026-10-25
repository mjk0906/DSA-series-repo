class Solution {
  public:
    void add(vector<string>&ans,string& s,string curr,int i){
        if(i == s.size()){
            ans.push_back(curr) ;
            return ;
        }
        //have basically only 2 options ,eiher take the element or leave the element at every element
        //take the element
        curr.push_back(s[i]);
        add(ans,s,curr,i+1) ;
        //leave the element
        curr.pop_back() ;
        add(ans,s,curr,i+1) ; //never give i++ in these type of situations
    }
    vector<string> powerSet(string &s) {
        // Code here
        vector<string> ans ;
        string curr ;
        add(ans,s,curr,0) ;
        
        sort(ans.begin(),ans.end()) ;
        return ans ;
    }
}
//gfg problem just some more details that the normal powerSet problem, check it