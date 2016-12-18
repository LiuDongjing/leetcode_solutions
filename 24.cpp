//Swap Nodes in Pairs
//容易出错的地方：交换之后，忘了与前后节点连接
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1, *p2, *p3;
        if (head == NULL) 
            return NULL;
        if (head->next == NULL) {
            return head;
        }
        p1 = head;
        p2 = head->next;
        head = p2;
        p3 = NULL;
        while(p2 != NULL) {
            p1->next = p2->next;
            p2->next = p1;
            if (p3 == NULL) {
                p3 = p1;
            }
            else {
                p3->next = p2;
                p3 = p1;
            }
            p1 = p1->next;
            if (p1 != NULL)
                p2 = p1->next;
            else
                p2 = NULL;
        }
        p3->next = p1;
        return head;
    }
};