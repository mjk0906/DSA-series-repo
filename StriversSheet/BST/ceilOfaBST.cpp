/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        Node* curr = root;
        int Ceil = -1 ;
        while(curr!=NULL){
            if(curr->data>x){
                Ceil=curr->data; //when we find a node greater than curr, just assume it is the ceil. Anyhow we are going leftwards so It will be the smallest larger element than x anyhow
                curr=curr->left ;
            }
            else if(curr->data<x){
                curr=curr->right ;
            }
            else{
                Ceil=curr->data; //if we find the element x then we can just say that the ceil is x itself
                break ;
            }
        }
        return Ceil ;
    }
};
//very interesting question
