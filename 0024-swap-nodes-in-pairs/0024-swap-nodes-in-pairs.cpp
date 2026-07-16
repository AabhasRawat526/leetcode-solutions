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
void reverse (ListNode*head,int times){
    ListNode*current=head;
    ListNode*previous=nullptr;
    while(times--){
        ListNode*next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    return;
}
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr){
            return nullptr;
        }
        ListNode*left=head;
        ListNode*previousleft=nullptr;
        ListNode*res=nullptr;
        int size=2;
        while(true){
            ListNode*right=left;
            for (int i=0;i<size-1;i++){
                if (right==nullptr){
                    break;
                }
                right=right->next;
            }
                if (right){     // left right mil gya hai
                   ListNode*nextleft=right->next;
                   reverse(left,size);
                   if (previousleft){
                    previousleft->next=right;
                   }
                   previousleft=left;
                   if (res==nullptr){
                    res=right;
                   }
                   left=nextleft;
                }
                else {
                    if (previousleft){
                        previousleft->next=left;
                    }
                    if (res==nullptr){
                        res=left;
                    }
                    break;
                }
         }
         return res;
    }
};