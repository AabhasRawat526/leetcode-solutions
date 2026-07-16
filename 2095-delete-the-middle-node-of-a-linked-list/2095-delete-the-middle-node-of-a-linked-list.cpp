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
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*previous=nullptr;
        if (fast->next==nullptr){
            return nullptr;
        }
        while(fast!=nullptr and fast->next!=nullptr){
            previous=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        previous->next=slow->next;
        delete slow;
        return head;
    }
};