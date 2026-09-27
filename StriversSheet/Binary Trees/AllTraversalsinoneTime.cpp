/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> post , in , pre ;
        stack<pair<Node*,int>> st ;
        st.push({root,1}) ;
        while(!st.empty()){
            Node* node = st.top().first ;
            int state = st.top().second ;
            
            if(state==1){
                pre.push_back(node->data) ;
                st.top().second++ ;
                if(node->left != NULL){
                    st.push({node->left , 1}) ;
                }
            }
            else if(state==2){
                in.push_back(node->data) ;
                st.top().second++ ;
                if(node->right!=NULL){
                    st.push({node->right,1}) ;
                }
            }
            else{
                post.push_back(node->data) ;
                st.pop() ;
            }
        }
        return post ;
    }
};

//important thing here is using the state key or variable 