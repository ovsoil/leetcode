#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

struct ListNode{
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(NULL){}
};


void PushBack(ListNode *list)
{
    if(NULL == list)
        return;
    ListNode *node = new ListNode(rand());
    ListNode *p = list;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = node;
}

void PushBack(ListNode *list, int value)
{
    if(NULL == list)
        return;
    ListNode *node = new ListNode(value);
    ListNode *p = list;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = node;
}
void PushFront(ListNode *head)
{
    ListNode *node = new ListNode(rand());
    node->next = head->next;
    head->next = node;
}

void PushFront(ListNode *head, int value)
{
    ListNode *node = new ListNode(value);
    node->next = head->next;
    head->next = node;
}

ListNode* CreateList(int len)
{
    ListNode dummy(-1);
    for (int i = 0; i < len; ++i) {
        PushFront(&dummy, i);
    }
    return dummy.next;
}

void PrintList(ListNode *list)
{
    while(NULL != list){
        cout << list->value << "->";
        list = list->next;
    }
    cout << "NULL" << endl;
}
#endif //_LIST_H_
