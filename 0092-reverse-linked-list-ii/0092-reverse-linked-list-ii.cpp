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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr){
            return nullptr;
        }
        if (left==right){
            return head;
        }
        int pos=1;
        ListNode*t=head;
        ListNode*before=nullptr;
        int times=right-left+1;
        while(t!=nullptr){
            if (pos<left){
                before=t;
                t=t->next;
                pos++;
                continue;
            }
            ListNode*current=t;
            ListNode*previous=nullptr;
            while(times>0){
                ListNode*next=current->next;
                current->next=previous;
                previous=current;
                current=next;
                times--;
            }
            t->next=current;
            if (before){
                before->next=previous;
                return head;
            }
            return previous;
        }
        return head;
    }
};