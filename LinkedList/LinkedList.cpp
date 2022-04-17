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

class LinkedList
{
private:
    ListNode *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    void traverse()
    {
        ListNode *ptr = head;
        cout << "Linked List -> ";
        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    };
    void insert(int x)
    {
        if (!head)
        {
            head = new ListNode(x);
        }
        else
        {
            ListNode *ptr = new ListNode(x);
            ListNode *P = head;
            while (P->next)
            {
                P = P->next;
            }
            P->next = ptr;
        }
    };

    ListNode *reverseHelper(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *LastNode = reverseHelper(head->next);
        head->next->next = head;
        head->next = nullptr;
        return LastNode;
    }
    void reverse()
    {
        head = reverseHelper(head);
    }

    ListNode *reverse2()
    {
        if (!head || !head->next)
        {
            return;
        }
        ListNode *previous = nullptr;
        ListNode *cureent = head;
        ListNode *next = nullptr;
        while (cureent)
        {
            next = cureent->next;
            cureent->next = previous;
            previous = cureent;
            cureent = next;
        }
        return head = previous;
    }
    void swapPairs()
    {
        if (!head || !head->next)
            return;

        // 1. swapping head and head->next
        ListNode *p = head;
        head = head->next;
        p->next = head->next;
        head->next = p;

        // 2. make previous , current , next
        ListNode *previous = nullptr;
        ListNode *current = nullptr;
        ListNode *next = nullptr;

        previous = head->next;

        if (previous->next)
        {
            current = previous->next;
        }
        else
        {
            return;
        }

        if (current->next)
        {
            next = current->next;
        }
        else
        {
            return;
        }

        while (true)
        {
            previous->next = next;
            current->next = next->next;
            next->next = current;

            previous = current;
            if (previous->next)
            {
                current = previous->next;
            }
            else
            {
                return;
            }
            if (current->next)
            {
                next = current->next;
            }
            else
            {
                return;
            }
        }
    }

    void MergeSort()
    {
    }
};

int main()
{
    LinkedList ll;
    ll.insert(5);
    ll.insert(15);
    ll.insert(35);
    ll.insert(54);
    ll.insert(2);
    ll.insert(5564);
    ll.traverse();
    ll.swapPairs();

    ll.traverse();

    return 0;
}