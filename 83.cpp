// Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while(p != NULL) {
            ListNode *l = p->next;
            while(l != NULL && l->val == p->val){
                p->next=l->next;
                delete l;
                l = p->next;
            }
            p = l;
        }
        return head;
    }
};
