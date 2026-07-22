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
ListNode*merge(ListNode* l1, ListNode* l2){
    ListNode*dummy=new ListNode(0);
    ListNode*current=dummy;
    while(l1!=nullptr and l2!=nullptr){
        if (l1->val < l2->val){
            current->next=l1;
            l1=l1->next;
        }
        else {
            current->next=l2;
            l2=l2->next;
        }
        current=current->next;
    }
    if (l1!=nullptr){
        current->next=l1;
    }
    if (l2!=nullptr){
        current->next=l2;
    }
    return dummy->next;
}


ListNode*divide(vector<ListNode*>& lists,int left,int right){
    if (left==right){
        return lists[left];
    }
    int mid=(left+right)/2;

    ListNode*l1=divide(lists,left,mid);

    ListNode*l2=divide(lists,mid+1,right);

    return merge(l1,l2);
}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }
        return divide(lists,0,lists.size()-1);
    }
};