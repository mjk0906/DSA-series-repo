class BSTIterator {
public:
    stack<TreeNode*> s ;
    BSTIterator(TreeNode* root) {
        storeLeftnodes(root);
    }
    void storeLeftnodes(TreeNode* root){
        while(root!=NULL){
            s.push(root) ;
            root=root->left;
        }
    }
    int next() {
        TreeNode* ans = s.top() ;
        s.pop() ;
        if(ans->right){
            storeLeftnodes(ans->right) ;
        }
        return ans->val ;
    }
    
    bool hasNext() {
        return s.size()>0 ;
    }
};