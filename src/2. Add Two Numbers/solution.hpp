/**
 * @file solution.hpp
 * @brief 
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
 * @author ovsoil
 * @version 
 * @date 2017-10-31
 */

/* Copyright (C) 
 * 2017 - ovsoil
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
