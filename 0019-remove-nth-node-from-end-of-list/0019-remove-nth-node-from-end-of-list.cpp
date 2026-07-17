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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*current=head;
        ListNode*previous=dummy;
        for (int i=0;i<n;i++){
            current=current->next;
        }
        while(current!=nullptr){
            current=current->next;
            previous=previous->next;
        }
        ListNode*temp=previous->next;
        previous->next=temp->next;
        delete temp;
        return dummy->next;
    }
};