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
Node* getRightmost(Node* root){
    Node* ans;
    while(root!=NULL){
        ans=root ;
        root=root->right;
    }
    return ans ;
}
Node* getLeftmost(Node* root){
    Node* ans ;
    while(root!=NULL){
        ans = root ;
        root=root->left;
    }
    return ans ;
}
Node* pred = NULL ;
Node* succ = NULL ;
vector<int> getPredSucc(Node* root,int key){
    Node* curr = root ;
    while(curr != NULL){
        if(key>curr->data){
            pred = curr ;
            curr = curr->right;
        }
        else if(key<curr->data){
            succ = curr ;
            curr = curr->left;
        }
        else if(key==curr->data){

            if(curr->left!=NULL){
                pred = getRightmost(curr->left);
            }
            if(curr->right!=NULL){
                succ = getLeftmost(curr->right);
            }
            break ;
        }
    }
    vector<int> ans ;
    ans.push_back(pred->data);
    ans.push_back(succ->data);
    return ans ;
}

int main(){

    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 6;
    vector<int> ans = getPredSucc(root, key);

    cout << "predecessor: " << ans[0] << endl;
    cout << "successor: " << ans[1] << endl;

    return 0;
}

//tc would be O(log(N)) or O(H) where H is the height of the binary tree
//sc would be O(1) ;