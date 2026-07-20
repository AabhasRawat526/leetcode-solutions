
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr){
            return nullptr;
        }
        if (head->next==nullptr){
            return head;
        }
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*current=head;
        ListNode*previous=dummy;
        while(current!=nullptr and current->next!=nullptr){
            if (current->next!=nullptr and current->val == current->next->val){
                while(current->next!=nullptr and current->val == current->next->val){
                    current=current->next;
                }
                previous->next=current->next;
            }
            else {
                previous=previous->next;
            }
            current=current->next;
        }
        return dummy->next;
    }
};