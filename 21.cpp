//Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        ListNode *p1 = l1, *p2 = l2, *r = NULL, *t = NULL, *head = NULL;
        if (p1 == NULL) {
            head = r = p2;
            p2 = p2->next;
        }
        else if (p2 == NULL) {
            head = r = p1;
            p1 = p1->next;
        }
        else {
            if (p1->val < p2->val) {
                head = r = p1;
                p1 = p1->next;
            }
            else {
                head = r = p2;
                p2 = p2->next;
            }
        }
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                r->next = p1;
                r = r->next;
                p1 = r->next;
            }
            else if (p1->val > p2->val) {
                r->next = p2;
                r = r->next;
                p2 = r->next;
            }
            else {
                r->next = p1;
                r = r->next;
                p1 = r->next;
                r->next = p2;
                r = r->next;
                p2 = r->next;
            }
        }
        if (p1 != NULL)
            r->next = p1;
        if (p2 != NULL)
            r->next = p2;
        return head;
    }
};
