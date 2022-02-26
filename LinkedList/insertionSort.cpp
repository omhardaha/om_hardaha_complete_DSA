#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *insertionSort(ListNode *p)
{
    ListNode *k = nullptr;

    while (p)
    {
        if (!k)
        {
            ListNode *temp = p;
            p = p->next;
            temp->next = nullptr;
            k = temp;
        }

        p = p->next;
    }

    return k;
}
int main()
{
    ListNode *p = new ListNode(6);
    p->next = new ListNode(8);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(7);
    p->next->next->next->next = new ListNode(2);
    p = insertionSort(p);

    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}