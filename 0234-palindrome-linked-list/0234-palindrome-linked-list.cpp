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
        if (head==nullptr){
            return true;
        }
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode*current=slow;
        ListNode*previous=nullptr;

        while(current!=nullptr){
            ListNode*next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }

        while(previous!=nullptr){
            if (head->val!=previous->val){
                return false;
            }
            head=head->next;
            previous=previous->next;
        }
        return true;

    }
};