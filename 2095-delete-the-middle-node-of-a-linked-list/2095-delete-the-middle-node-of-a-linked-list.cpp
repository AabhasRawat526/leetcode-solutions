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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next==nullptr){
            return nullptr;
        }
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*previous=nullptr;
        while(fast!=nullptr and fast->next!=nullptr){
            previous=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        previous->next=slow->next;
        delete slow;
        return head;
    }
};