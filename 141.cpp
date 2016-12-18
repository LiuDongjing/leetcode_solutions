//Linked List Cycle
//下面的只是基本方法，还可以不借助额外的空间来解决
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
    bool hasCycle(ListNode *head) {
        set<ListNode*> his;
        ListNode* p = head;
        while(p != NULL) {
            if(his.find(p) != his.end()) {
                return true;
            }
            his.insert(p);
            p = p->next;
        }
        return false;
    }
};
