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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head ;
        vector<int> ll ;
        while(temp!=NULL){
            ll.push_back(temp->val) ;
            temp = temp->next ;
        }
        reverse(ll.begin(),ll.end()) ;
        temp = head ;
        int i=0 ;
        bool pal = true ;
        while(temp!=NULL && i<ll.size()){
            if(temp->val!=ll[i]){
                pal = false ;
            }
            temp=temp->next ;
            i++ ;
        }
        return pal ;
    }
};

//own coded, simple