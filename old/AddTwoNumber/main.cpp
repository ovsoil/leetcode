

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v):val(v), next(NULL){}
}

class Solution
{
public:
    ListNode* AddTwoNumbers(ListNode *list1, ListNode *list2)
    {
        int carry = 0;
        ListNode head(-1);
        ListNode *pre = &head;
        for(; 
            list1 != NULL || list2 != NULL;
            list1 = list1 == NULL? NULL : list1->next, 
            list2 = list2 == NULL? NULL : list2->next,
            pre = prev->next)
        {
            const int a = list1 == NULL? 0 : list1.val;
            const int b = list2 == NULL? 0 : list2.val;
            const int r = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            pre->next = new ListNode(r);
        }
        if (carry > 0)
            pre->next = new ListNode(carry);

        return head.next;
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    ListNode head(-1);
    ListNode *l1, *l2;
    int a[3] = [1, 8, 4];
    for (int i = 0; i < 3; ++i) {
        
    }
    int b[4] = [5, 4, 7, 9];
    
    return 0;
}
