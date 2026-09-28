/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head ;
        }
        ListNode* temp = head ;
        int size = 0 ;
        while(temp!=NULL){
            temp=temp->next ;
            size++ ;
        }
        int k = size-n ;
        if(k==0){
            ListNode* del = head ;
            head = head->next ;
            delete del ;
            return head ;
        }
        temp=head ;
        ListNode* prev = NULL ;
        for(int i=0;i<k;i++){
            prev = temp ;
            temp = temp->next ;
        }
        prev->next = temp->next ;  //prev->next not defined when the node to be deleted is head itself
        delete temp ;
        return head ;
    }
};

//this is easy but just handle the base cases carefully