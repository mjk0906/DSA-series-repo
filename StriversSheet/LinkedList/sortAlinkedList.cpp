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
    ListNode* merge(ListNode* left , ListNode* right){
        ListNode* dummy = new ListNode(0) ;
        ListNode* curr = dummy ;
        while(right!=NULL && left!=NULL){
            if(left->val <= right->val){
                curr->next = left ;
                left = left->next ;
            }else{
                curr->next = right ;
                right = right->next ;
            }
            curr=curr->next ;
        }
        if(left!=NULL){
            curr->next = left ;
        }else{
            curr->next = right ;
        }
        return dummy->next ;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return head ;
        }
        ListNode* fast = head->next ;
        ListNode* slow = head ;
        while (fast!=NULL && fast->next!=NULL){
            slow= slow->next ;
            fast = fast->next->next ;
        }
        //divide the list 
        ListNode* left = head ;
        ListNode* right = slow->next ;
        slow->next = NULL ;

        left = sortList(left) ;
        right = sortList(right) ;

        return merge(left,right) ;
    }
};

// totally dependent on whether you know merge sort or not 