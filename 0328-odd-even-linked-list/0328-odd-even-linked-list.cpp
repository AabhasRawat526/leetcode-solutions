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
    ListNode* oddEvenList(ListNode* head) {
        if (head==nullptr){
            return nullptr;
        }
        if (head->next==nullptr){
            return head;
        }
        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*evennode=even;
        while(even!=nullptr and even->next!=nullptr){
            odd->next=even->next;       // connects odd to the odd 
            odd=even->next;             // value of the odd is updated
            even->next=odd->next;       // same connects even to the even
            even=odd->next;             // value of the even is updated
            
        }

        odd->next=evennode;
        return head;
    }
};