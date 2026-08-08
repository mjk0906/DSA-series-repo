/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

//note it mann