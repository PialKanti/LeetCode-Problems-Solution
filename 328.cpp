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

ListNode *oddEvenList(ListNode *head)
{
    ListNode *odd, *even, *temp;
    ListNode *oddHead = NULL;
    ListNode *evenHead = NULL;

    if (!head)
        return head;

    while (head)
    {
        if (!oddHead)
        {
            oddHead = head;
            odd = head;
        }
        else
        {
            odd->next = head;
            odd = odd->next;
        }

        temp = head;
        head = head->next;
        temp->next = NULL;

        if (head)
        {
            if (!evenHead)
            {
                evenHead = head;
                even = head;
            }
            else
            {
                even->next = head;
                even = even->next;
            }

            temp = head;
            head = head->next;
            temp->next = NULL;
        }
    }

    odd->next = evenHead;
    return oddHead;
}
