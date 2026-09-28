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
    ListNode* reverseNode(ListNode* curr,ListNode* prev){
        if(curr==NULL){
            return prev ;
        }
        ListNode* next = curr->next ;
        curr->next = prev ; //main line
        
        return reverseNode(next,curr) ;   //dont use next only in the recursive function
    }
    ListNode* reverseList(ListNode* head) {
        return reverseNode(head,NULL) ;
    }
};

//easy code, just focus once