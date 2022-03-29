#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-trie-prefix-tree
class Trie
{
public:
    struct Node
    {
        Node *links[52];
        bool flag = false;
        bool containsKey(char key)
        {
            return links[key - 'a'];
        }
        bool hasEnd()
        {
            return flag;
        }
        Node *getNode(char key)
        {
            return links[key - 'a'];
        }
        void put(char key)
        {
            links[key - 'a'] = new Node();
        }
        void setEnd()
        {
            flag = true;
        }
    };
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *p = root;
        for (char key : word)
        {
            if (!p->containsKey(key))
            {
                p->put(key);
            }
            p = p->getNode(key);
        }
        p->setEnd();
    }

    bool search(string word)
    {
        Node *p = root;
        for (char key : word)
        {
            if (!p->containsKey(key))
            {
                return false;
            }
            p = p->getNode(key);
        }
        return p->hasEnd();
    }
};

int main()
{

    Trie Dictionary;
    Dictionary.insert("javascripts");
    Dictionary.insert("FooBar");
    Dictionary.insert("FooBarTest");
    Dictionary.insert("FootBall");
    Dictionary.insert("FrameBuffer");
    Dictionary.insert("ForceFeedBack");

    cout << Dictionary.search("FootBall") << endl;
    return 0;
}