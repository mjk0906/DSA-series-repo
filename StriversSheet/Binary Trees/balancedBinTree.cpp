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
class Solution {
public:
    int check(TreeNode* root){
        if(root==NULL){
            return 0 ;
        }
        int left = check(root->left) ;
        int right = check(root->right) ;
        if(left == -1 || right== -1){
            return -1 ;
        }
        else if(abs(left-right)>1){
            return -1 ;
        }else{
            return 1 + max(left,right) ;
        }
    }
    bool isBalanced(TreeNode* root) {
        int var = check(root) ;
        return var != -1 ;
    }
};

//may look easy but not an easy problem, it is very logical