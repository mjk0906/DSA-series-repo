#include <iostream>
#include <vector> 
using namespace std ;

class Info{
public:
    int max , min ,size ;

    Info(int mx,int mn,int sz){
        max = mx ;
        min = mn ;
        size = sz ;
    }
};

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

Info helper(Node* root){
    if(root==NULL){
        return Info(INT_MIN,INT_MAX,0);
    }
    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data>left.max && root->data < right.min){

        int currMin = min(root->data,left.min) ;
        int currMax = max(root->data,right.max) ;
        int currSize = left.size + right.size + 1;

        return Info(currMax , currMin ,currSize);
    }

    return Info(INT_MAX ,INT_MIN ,max(right.size,left.size));

}

int largestBST(Node* root){
    Info info = helper(root) ;
    return info.size ;
}

int main() {

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout<<largestBST(root)<<endl ;
}