#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

class MyLinkedList
{
public:
    ListNode *head;
    ListNode *tail;

    MyLinkedList()
    {
        head = tail = nullptr;
    }

    int get(int index)
    {
        ListNode *p = head;
        while (p && index--)
        {
            p = p->next;
        }
        return (p) ? p->val : -1;
    }

    void addAtHead(int val)
    {
        if (!head)
        {
            head = new ListNode(val);
            tail = head;
        }
        else
        {
            ListNode *p = new ListNode(val);
            p->next = head;
            head = p;
        }
    }

    void addAtTail(int val)
    {
        if (!head)
        {
            head = new ListNode(val);
            tail = head;
        }
        else
        {
            ListNode *p = new ListNode(val);
            tail->next = p;
            tail = p;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        ListNode *p = head;
        index--;
        while (p && index--)
        {
            p = p->next;
        }
        if (p)
        {
            ListNode *p1 = p->next;
            if (p)
                p->next = new ListNode(val, p1);
            if (!p1)
                tail = p->next;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            head = head->next;
            return;
        }
        else
        {

            ListNode *p = head;
            index--;
            while (p && index--)
            {
                p = p->next;
                cout << "df";
            }
            if (p && p->next)
                p->next = p->next->next;
            if (p && !p->next)
                tail = p;
        }
    }
};
int main()
{

    return 0;
}