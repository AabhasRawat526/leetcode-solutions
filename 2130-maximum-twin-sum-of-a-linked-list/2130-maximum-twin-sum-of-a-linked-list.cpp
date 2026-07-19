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
    int pairSum(ListNode* head) {
        if (head==nullptr){
            return 0;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=nullptr and fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode*current=slow;
        ListNode*previous=nullptr;
        while(current!=nullptr){
            ListNode*next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        int answer=0;
        while(previous!=nullptr){
            answer=max(answer,head->val+previous->val);
            head=head->next;
            previous=previous->next;
        }
        return answer;
    }
};