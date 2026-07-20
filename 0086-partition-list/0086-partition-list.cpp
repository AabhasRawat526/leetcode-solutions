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
    ListNode* partition(ListNode* head, int x) {
        if (head==nullptr){
            return nullptr;
        }
        if (head->next==nullptr){
            return head;
        }
        ListNode*current=head;
        ListNode*smalldummy=new ListNode(0);
        ListNode*largedummy=new ListNode(0);
        ListNode*small=smalldummy;
        ListNode*large=largedummy;
        while(current!=nullptr){
            if (current->val <x){
                small->next=current;
                small=small->next;
            }
            else{
                large->next=current;
                large=large->next;
            }
            current=current->next;
        }
        small->next=largedummy->next;
        large->next=nullptr;
        return smalldummy->next;
    }
};