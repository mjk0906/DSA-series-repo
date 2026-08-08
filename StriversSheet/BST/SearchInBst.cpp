class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = NULL ;
        if(root==NULL){
            return NULL ;
        }
        if(root->val>val){
            ans=searchBST(root->left,val) ;
        }else if(root->val<val){
            ans=searchBST(root->right,val) ;
        }else{
            return root ;
        }
        return ans ;
    }
};

//easy broo