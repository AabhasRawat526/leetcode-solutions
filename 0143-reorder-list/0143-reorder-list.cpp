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
    void reorderList(ListNode* head) {
        if (head==nullptr){
            return;
        }
        if (head->next==nullptr){
            return;
        }
        ListNode*fast=head->next;
        ListNode*slow=head;
        while(fast!=nullptr and fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*second=slow->next;
        slow->next=nullptr;
        ListNode*current=second;
        ListNode*previous=nullptr;
        while(current!=nullptr){
            ListNode*next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        ListNode*first=head;
        second=previous;
        while(second!=nullptr){
            ListNode*next1=first->next;
            ListNode*second2=second->next;
            first->next=second;
            second->next=next1;

            first=next1;
            second=second2;
        }

    }
};
