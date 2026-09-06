class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                st.push(s[i]) ;
            }else{
                if(st.size()==0){
                    return false ;
                }
                if(st.top()=='{' && s[i]=='}' || st.top()=='[' && s[i]==']' || st.top()=='(' && s[i]==')'){
                    st.pop() ;
                }else{
                    return false ;
                }
            }
        }
        return st.size()==0 ; 
    }
};
//there is one more version of solving this problem 
//this is more easier to write the code version 

class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;
        for(char x : s){
            if(x=='('){
                st.push(')') ;
            }else if(x=='{'){
                st.push('}') ;
            }else if(x=='['){
                st.push(']') ;
            }else{
                if(st.empty() || st.top()!=x){
                    return false ;
                }
                st.pop() ;
            }
        }
        return st.empty() ;
    }
};