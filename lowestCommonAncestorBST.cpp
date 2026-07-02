class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL ;
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }else if(root->val<q->val && root->val<p->val){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return root;
        }
        return NULL ;
    }
};
//leetcode 235 but the tc here is O(logn) as the decision is taken whether to travel left or right, hence worst case would be travelling whole height once in left or right subtree
//therefore balanced bst would have a height of O(logbase2n)