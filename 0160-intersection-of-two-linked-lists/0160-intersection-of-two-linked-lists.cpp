/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA=0;
        int lengthB=0;

        ListNode*a=headA;
        ListNode*b=headB;

        while(a!=nullptr){
            lengthA++;
            a=a->next;
        }

        while(b!=nullptr){
            lengthB++;
            b=b->next;
        }

        a=headA;
        b=headB;

        while(lengthA<lengthB){
            b=b->next;
            lengthB--;
        }

        while(lengthA>lengthB){
            a=a->next;
            lengthA--;
        }

        while(a!=b){
            a=a->next;
            b=b->next;
        }
        return a;
    }
};