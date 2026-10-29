class Solution {
  public:
    void insertElement(stack<int> &st , int top){
        if(st.empty() || top>=st.top()){
            st.push(top) ;
            return ;
        }
        int topElement = st.top() ;
        st.pop() ;
        
        insertElement(st,top) ;
        
        st.push(topElement) ;
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return ;
        }
        int x = st.top() ;
        st.pop() ;
        
        sortStack(st) ;
        
        insertElement(st,x) ;
    }
};
//good and logical problem 