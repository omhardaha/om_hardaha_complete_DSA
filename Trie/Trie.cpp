#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-trie-prefix-tree
struct Node
{
    Node *links[26];
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
class Trie
{
public:
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
    // Dictionary.insert("men");
    // Dictionary.insert("dog");
    // Dictionary.insert("tree");
    Dictionary.insert("javascript");
    Dictionary.insert("hpp");

    cout << Dictionary.search("hpp") << endl;
    cout << Dictionary.search("nodejs") << endl;
    cout << Dictionary.startsWith("git") << endl;
    return 0;
}