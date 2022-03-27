#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie
{
public:
    struct Node
    {
        Node *links[26];
        Node *dot[1];
        bool flag = false;
        bool containsKey(char key)
        {
            if (key == '.')
            {
                return dot[0];
            }
            return links[key - 'a'];
        }
        bool hasEnd()
        {
            return flag;
        }
        Node *getNode(char key)
        {
            if (key == '.')
            {
                return dot[0];
            }
            return links[key - 'a'];
        }
        void put(char key)
        {
            if (key == '.')
            {
                dot[0] = new Node();
            }
            else
            {
                links[key - 'a'] = new Node();
            }
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

    bool startsWith(string word)
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
        return true;
    }
};

int main()
{

    Trie Dictionary;
    Dictionary.insert("bad");
    Dictionary.insert("dad");
    Dictionary.insert("mad");
    Dictionary.insert(".ad");

    cout << Dictionary.search("bad") << endl;
    cout << Dictionary.search(".ad") << endl;
    cout << Dictionary.search("b..") << endl;
    return 0;
}