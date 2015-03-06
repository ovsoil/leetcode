#include "list.h"

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n){
        int count = n - m;
        if(count <= 0)
            return head;
        ListNode *pre, *p1, *p2;
        pre = head;
        while(--m > 0)
            pre = pre->next;
        p1 = pre->next;
        p2 = p1->next;
        while(count-- > 0)
        {
            p1->next = p2->next;
            p2->next = pre->next;
            pre->next = p2;
            p2 = p1->next;
        }
        return head->next;
    }
};


int main()
{
    ListNode *list1 = CreateList(10);
    PrintList(list1);
    ListNode dummy(-1);
    for (int i = 0; i < 10; ++i) {
        PushBack(&dummy, i);
    }
    PrintList(dummy.next);
    
    Solution s;
    PrintList(s.reverseBetween(&dummy, 3, 6));
    PrintList(dummy.next);

    return 0;
}
