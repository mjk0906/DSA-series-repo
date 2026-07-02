class Solution {
public:
    TreeNode* prev = NULL;
    int ans = INT_MAX ;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return INT_MAX ;
        if(root->left){
            int leftmin=minDiffInBST(root->left);
            ans=min(ans,leftmin);
        }
        if(prev!=NULL){
            ans=min(ans,root->val-prev->val);
        }
        prev=root;
        if(root->right){
            int rightmin = minDiffInBST(root->right);
            ans=min(ans,rightmin);
        }
        return ans;
    }
};
//solution for prob 783 leetcode