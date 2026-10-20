/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int cnt0 = 0 ;
        int cnt1 = 0 ;
        int cnt2 = 0 ;
        Node* temp = head ;
        while(temp!=NULL){
            if(temp->data == 0){
                cnt0++ ;
            }else if(temp->data == 1){
                cnt1++ ;
            }else{
                cnt2++ ;
            }
            temp = temp->next ;
        }
        temp = head ;
        while(temp!=NULL){
            if(cnt0>0){
                temp->data = 0 ;
                cnt0-- ;
            }else if(cnt1 > 0){
                temp->data = 1 ;
                cnt1-- ;
            }else if(cnt2 > 0){
                temp->data = 2 ;
                cnt2-- ;
            }
            temp=temp->next ;
        }
        return head ;
    }
};
//easy but crazy approach