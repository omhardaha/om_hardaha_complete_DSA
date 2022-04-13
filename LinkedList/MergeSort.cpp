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
void traverse(ListNode *head)
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
ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
{
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }
    if (head1->val > head2->val)
    {
        swap(head1, head2);
    }
    ListNode *merge = head1;
    ListNode *tail = merge;
    head1 = head1->next;

    while (head1 && head2)
    {
        while (head1 && head2 && head1->val <= head2->val)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        swap(head1, head2);
    }
    if (head1)
    {
        tail->next = head1;
    }
    else
    {
        tail->next = head2;
    }
    return merge;
}

ListNode *MergeSort(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    if (!head->next->next)
    {
        ListNode *p = head->next;
        head->next = nullptr;
        return mergeTwoLists(head, p);
    }
    ListNode *list1 = head;
    ListNode *l1 = middleNode(head);
    ListNode *list2 = l1->next;
    l1->next = nullptr;

    list1 = MergeSort(list1);
    traverse(list1);
    list2 = MergeSort(list2);
    traverse(list2);

    return mergeTwoLists(list1, list2);
}
int main()
{
    ListNode *head1 = new ListNode(24);
    head1->next = new ListNode(5);
    head1->next->next = new ListNode(9);
    head1->next->next->next = new ListNode(8);
    head1->next->next->next->next = new ListNode(7);

    traverse(head1);
    ListNode *mergerdList = MergeSort(head1);
    cout << "final - > ";
    traverse(mergerdList);

    ListNode *p1 = new ListNode(5);
    p1->next = new ListNode(24);

    ListNode *p2 = new ListNode(9);
    // traverse(mergeTwoLists(p1, p2));

    return 0;
}