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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dumy_head = new ListNode(0);
        auto p1 = l1, p2 = l2, p = dumy_head;
        auto carry = 0;
        while(p1 || p2){
            auto val1 = p1? p1->val: 0;
            auto val2 = p2? p2->val: 0;
            auto tmp = val1 + val2 + carry;
            carry = tmp / 10;
            p-> next = new ListNode(tmp % 10);
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
            p = p->next;
        }
        if(carry > 0)
            p->next = new ListNode(carry);
        return dumy_head->next;
    }
};
