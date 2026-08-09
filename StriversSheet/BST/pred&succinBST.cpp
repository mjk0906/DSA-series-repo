/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    Node* getSucc(Node* root){
        while(root!=NULL && root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    Node* getPred(Node* root){
        while(root!=NULL && root->right!=NULL){
            root=root->right ;
        }
        return root;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pred = NULL;
        Node* succ = NULL ;
        vector<Node*> ans ;
        Node* curr = root ;
        while(curr!=NULL){
            if(curr->data>key){
                succ = curr ;
                curr=curr->left ;
            }else if(curr->data<key){
                pred = curr ;
                curr=curr->right ;
            }else if(curr->data==key){
                if(curr->left!=NULL){
                    pred = getPred(curr->left);
                }
                if(curr->right!=NULL){
                    succ = getSucc(curr->right);
                }
                break ; //the most important statement of the code,once you have obtained the solution DON'T forget to end the loop
            }
        }
        ans.push_back(pred);
        ans.push_back(succ);
        return ans ;
    }
};

//gfg problem in strivers 