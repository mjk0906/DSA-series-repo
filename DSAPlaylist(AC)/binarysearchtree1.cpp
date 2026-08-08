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

Node* insert(Node* root , int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);  
    }
    return root ;
}
Node* buildbst(vector<int> arr){
    Node* root = NULL ;

    for(int val : arr){
        root = insert(root,val);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL) return ;

    inorder(root->left);
    cout<< root->data << " " ;
    inorder(root->right);
}
bool search(Node* root , int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key>root->data){
        return search(root->right,key);
    }
    if(key<root->data){
        return search(root->left,key);
    }
    return false ;
}
Node* findIS(Node* point){
    while(point!=NULL && point->left!=NULL){
        point=point->left ;
    }
    return point ;
}
Node* delNode(Node* root, int key){
    if(root==NULL){
        return NULL ;
    }
    if(root->data<key){
        root->right=delNode(root->right,key);
    }else if (root->data>key){
        root->left=delNode(root->left,key);
    }else{//root==key 
        if(root->right==NULL){
            Node* temp = root->left ;
            delete root;
            return temp ;
        }
        else if(root->left==NULL){
            Node* temp=root->right;
            delete root ;
            return temp ;
        }else{
            Node* IS = findIS(root->right);
            root->data = IS->data ;
            root->right = delNode(root->right,IS->data);
        }
    }
    return root ;
}
int main(){
    vector<int> arr = {2,1,4,3,5} ;
    Node* root = buildbst(arr);
    inorder(root);
    cout<<endl;
    cout<< search(root,6) << endl ;
    delNode(root,4);
    inorder(root);
    cout<<endl;
}