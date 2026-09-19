/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        // code here
        Node* newNode = new Node(x) ;
        if(head==NULL){
            return newNode ;
        }
        int i= 0 ;
        Node* temp = head ;
        while(i<p){
            temp=temp->next ;
            i++ ;
        }
        Node* nextNode = temp->next ;
        
        temp->next = newNode ;
        newNode->prev = temp ;
        
        newNode->next = nextNode ;
        
        if(nextNode!=NULL){
            nextNode->prev = newNode ;
        }
        return head ;
    }
};
//easy code