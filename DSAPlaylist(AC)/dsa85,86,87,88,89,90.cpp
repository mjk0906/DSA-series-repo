#include <iostream>
#include <vector> 
#include <queue>
#include <map>
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
int height(Node* root){
    if(root==NULL){
        return 0 ;
    }
    int leftht = height(root->left);
    int rightht = height(root->right);
    return max(leftht,rightht)+1 ;
}
int sum(Node* root){
    if(root==NULL){
        return 0 ;
    }
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    return leftsum+rightsum+root->data ;
}
int count(Node* root){
    if(root==NULL){
        return 0 ;
    }
    int leftcount=count(root->left);
    int rightcount=count(root->right);
    return leftcount+rightcount+1 ;
}
bool isSame(Node* p,Node* q){
    if(p==NULL||q==NULL){
        return p==q ;
    }
    bool leftSame = isSame(p->left,q->left);
    bool rightSame = isSame(p->right,q->right);
    return leftSame && rightSame && p->data == q->data ;
}
void topview(Node* root){
    queue<pair<Node*,int>>q ;
    q.push({root,0});
    map<int,int>m ;
    while(q.size()>0){
        Node* curr = q.front().first ;
        int x = q.front().second ;
        q.pop();
        if(m.find(x)==m.end()){ //find has tc of O(logn)
            m[x]=curr->data ;
        }
        if(curr->left!=NULL){
            q.push({curr->left,x-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,x+1});
        }
    }
    for(auto it : m){
        cout<<it.second<<" " ;
    }
    cout<<endl ;
} //tc is O(nlogn)
void kthlevel(Node* root,int k){
    if(root==NULL){
        return ;
    }
    if(k==1){
        cout<<root->data<<" " ;
        return ;
    }
    kthlevel(root->left,k-1);
    kthlevel(root->right,k-1);
}
int sumtree(Node* root){
    if(root==NULL){
        return 0 ;
    }
    int leftSum = sumtree(root->left);
    int rightSum = sumtree(root->right);
    root->data+=leftSum + rightSum ;
    return root->data ;

}

int main(){
    vector<int> preorder1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    vector<int> preorder2 = {1,2,-1,-1,3,-1,-1,-1,5,-1,-1} ;
    Node* root2 = buildtree(preorder2) ;
    idx = -1 ;
    Node* root1 = buildtree(preorder1) ;
    cout<<"height:"<<height(root1)<<endl ;
    cout<<"sum:"<<sum(root1)<<endl;
    cout<<"count:"<<count(root1)<<endl;
    if(isSame(root1,root2)){
        cout<<"same"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    topview(root1);
    kthlevel(root1,2);
    cout<<endl ;
    sumtree(root1);
    inorder(root1);
    cout<<endl;
    return 0 ;

    
    //level order traversal
    // cout<< root->right->left->data <<endl ;
    // inorder(root);
    // cout<<endl ;
    // queue<Node*> q ;
    // q.push(root);
    // q.push(NULL);

    // while(q.size()>0){
    //     Node* curr = q.front();
    //     q.pop();
    //     if(curr==NULL){
    //         if(!q.empty()){
    //             cout<<endl;
    //             q.push(NULL);
    //             continue ;
    //         }else{
    //             break ;
    //         }
    //     }
    //     cout<<curr->data<<" " ;
    //     if(curr->left!=NULL){
    //         q.push(curr->left);
    //     }
    //     if(curr->right!=NULL){
    //         q.push(curr->right);
    //     }
    // }
    // cout<<endl;
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
// class Solution {
// public:
//     vector<vector<int>> ans ;
//     vector<int> currLine ;
//     void lorder(TreeNode* root){
//         queue<TreeNode*> q ;
//         if(root==NULL){
//             return ;
//         }
//         q.push(root);
//         q.push(NULL);
//         while(q.size()>0){
//             TreeNode* curr = q.front();
//             q.pop();
//             if(curr==NULL){
//                 ans.push_back(currLine);
//                 currLine.clear();
//                 if(!q.empty()){
//                     q.push(NULL);
//                     continue ;
//                 }else{
//                     break ;
//                 }
//             }
//             currLine.push_back(curr->val);
//             if(curr->left!=NULL){
//                 q.push(curr->left);
//             }
//             if(curr->right!=NULL){
//                 q.push(curr->right);
//             }
//         }
//     }
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     lorder(root);
    //     return ans ;
    // }
// };