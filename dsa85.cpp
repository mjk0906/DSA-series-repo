#include <iostream>
#include <vector> 
#include <queue>
using namespace std ;

class Node{
    public:
        int data ;
        Node* left ;
        Node* right ;
        Node(int val){
            data = val ;
            left = right = NULL ;
        }
};

static int idx = -1 ;
Node* buildtree(vector<int> preorder){
    idx++ ;
    if(preorder[idx]==-1){
        return NULL ;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);
    return root ;
}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" " ;
    inorder(root->right);
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildtree(preorder) ;
    // cout<< root->right->left->data <<endl ;
    // inorder(root);
    // cout<<endl ;
    queue<Node*> q ;
    q.push(root);
    q.push(NULL);

    while(q.size()>0){
        Node* curr = q.front();
        q.pop();
        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue ;
            }else{
                break ;
            }
        }
        cout<<curr->data<<" " ;
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

//level order traversal leetcode_102
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
    vector<vector<int>> ans ;
    vector<int> currLine ;
    void lorder(TreeNode* root){
        queue<TreeNode*> q ;
        if(root==NULL){
            return ;
        }
        q.push(root);
        q.push(NULL);
        while(q.size()>0){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL){
                ans.push_back(currLine);
                currLine.clear();
                if(!q.empty()){
                    q.push(NULL);
                    continue ;
                }else{
                    break ;
                }
            }
            currLine.push_back(curr->val);
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        lorder(root);
        return ans ;
    }
};