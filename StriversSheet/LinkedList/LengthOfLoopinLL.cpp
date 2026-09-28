/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head ;
        Node* fast = head ;
        int length = 0 ;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next ;
            fast = fast->next->next ;
            
            if(slow==fast){
                fast = fast->next ;
                length++ ;
                while(slow!=fast){
                    fast = fast->next ;
                    length++ ;
                }
                return length ;
            }
        }
        return length ;
    }
};

//easy only beta but see the logic once thats it, own coded btw