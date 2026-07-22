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
    ListNode* removeNodes(ListNode* head) {
        ListNode*current=head;
        ListNode*previous=nullptr;
        while(current!=nullptr){
            ListNode*next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        int maximum=previous->val;
        ListNode*temp=previous;
        while(temp!=nullptr and temp->next!=nullptr){
            if (temp->next->val < maximum){
                temp->next=temp->next->next;
            }
            else {
                temp=temp->next;
                maximum=temp->val;
            }
        }
        ListNode*curr=previous;
        ListNode*first=nullptr;
        while(curr!=nullptr){
            ListNode*next1=curr->next;
            curr->next=first;
            first=curr;
            curr=next1;
        }
        return first;
    }
};