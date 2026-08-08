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
    TreeNode* justSmaller(stack<TreeNode*>&s){
        TreeNode* top = s.top();
        s.pop();
        TreeNode* temp = top->left ;
        while(temp){
            s.push(temp);
            temp=temp->right ;
        }
        return s.top();
    }
    TreeNode* justLarger(stack<TreeNode*>&s){
        TreeNode* top = s.top();
        s.pop();
        TreeNode* temp = top->right ;
        while(temp){
            s.push(temp); //the topmost node in the stack will be the just larger node for the passed node
            temp = temp->left ;
        }
        return s.top() ;
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>leftStack ;
        stack<TreeNode*>rightStack ;
        
        TreeNode* temp = root ;
        while(temp){
            leftStack.push(temp);
            temp=temp->left;
        }
        temp=root;
        while(temp){
            rightStack.push(temp);
            temp = temp->right ;
        }
        TreeNode* left = leftStack.top();
        TreeNode* right = rightStack.top();

        while(left!=right){
            int sum = left->val + right->val ;

            if(sum<k){
                left = justLarger(leftStack);
            }
            else if(sum==k){
                return true ;
            }
            else{
                right=justSmaller(rightStack) ;
            }
        }
        return false ;
    }
};
//very interesting application of stack data structure 
//really imp 