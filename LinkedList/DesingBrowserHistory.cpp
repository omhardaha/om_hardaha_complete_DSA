#include <bits/stdc++.h>
using namespace std;
class BrowserHistory
{
public:
    struct ListNode
    {
        string s;
        ListNode *next;
        ListNode *prev;
    };
    ListNode *history;
    ListNode *lastNode;
    BrowserHistory(string homepage)
    {
        history = new ListNode;
        history->s = homepage;
        history->prev = nullptr;
        lastNode = history;
    }

    void visit(string url)
    {
        ListNode *p = new ListNode;
        p->s = url;
        p->prev = lastNode;
        lastNode->next = p;
        lastNode = p;
    }

    string back(int steps)
    {
        while (steps-- && lastNode->prev)
        {
            lastNode = lastNode->prev;
        }
        return lastNode->s;
    }

    string forward(int steps)
    {
        while (steps-- && lastNode->next)
        {
            lastNode = lastNode->next;
        }
        return lastNode->s;
    }
};
int main()
{
    BrowserHistory b("om.com");
    b.visit("g");
    b.visit("f");
    b.visit("y");
    cout << b.back(1) << endl;
    cout << b.back(1) << endl;
    cout << b.forward(1) << endl;
    b.visit("l");
    cout << b.forward(2) << endl;
    cout << b.back(2) << endl;
    cout << b.back(7) << endl;
    return 0;
}