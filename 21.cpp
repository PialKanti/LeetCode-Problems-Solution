#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *mergedList = new ListNode();
    ListNode *iterator = mergedList;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            iterator->next = list1;
            list1 = list1->next;
        }
        else
        {
            iterator->next = list2;
            list2 = list2->next;
        }
        iterator = iterator->next;
    }

    while (list1)
    {
        iterator->next = list1;
        list1 = list1->next;
        iterator = iterator->next;
    }

    while (list2)
    {
        iterator->next = list2;
        list2 = list2->next;
        iterator = iterator->next;
    }

    return mergedList->next;
}