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
ListNode*reverse(ListNode*head,int times){
    ListNode*current=head;
    ListNode*previous=nullptr;
    while(times){
        ListNode*next=current->next;
        current->next=previous;
        previous=current;
        current=next;
        times--;
    }
    head->next=current;
    return previous;
}
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr){
            return nullptr;
        }
        ListNode*left=head;
        ListNode*previousleft=nullptr;
        ListNode*res=nullptr;
        while(left && left->next){
            ListNode*right=left->next;
            ListNode*nextleft=right->next;
            ListNode*newhead=reverse(left,2);
            if (previousleft){
                previousleft->next=newhead;
            }
            if (res==nullptr){
                res=newhead;
            }
            previousleft=left;
            left=nextleft;
        }
        if (res==nullptr){
            res=head;
        }
        return res;     
    }
};