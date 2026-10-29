class Solution {
  public:
    void insertAtBtom(stack<int>& st,int element){
        if(st.empty()){
            st.push(element) ;
            return ;
        }
        int top = st.top() ;
        st.pop() ;
        //call for the rest of the stack to insert at the bottom(element is to be inserted)
        insertAtBtom(st,element);
        //again place back the elements removed from the stack at each level
        st.push(top) ;
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return ;
        }
        int top = st.top() ;
        st.pop() ;
        //call for the rest of the stack
        reverseStack(st) ;
        //call to insert the curr top element at the bottom
        insertAtBtom(st,top) ;
    }
};

//very good problem, like u will be clear with the approach(no need to dry run)