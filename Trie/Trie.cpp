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

    bool advanceSearch(string word)
    {
        return advanceSearchHelper(word, 0, root);
    }
    bool advanceSearchHelper(string &word, int i, Node *dummy)
    {
        cout << word[i] << " ";
        if (word.size() == i)
        {
            cout << "finish" << endl;
            return dummy->hasEnd();
        }
        if (word[i] != '.')
        {
            if (dummy->containsKey(word[i]))
            {
                cout << "containsKey" << endl;
                if (advanceSearchHelper(word, i + 1, dummy->getNode(word[i])))
                {
                    return true;
                }
            }
            else
            {
                cout << "not containsKey" << endl;
                return false;
            }
        }
        else
        {
            for (auto node : dummy->links)
            {
                if (node)
                {
                    if (advanceSearchHelper(word, i + 1, node))
                    {
                        return true;
                    };
                }
            }
        }
        return false;
    }
};

int main()
{

    Trie Dictionary;
    // Dictionary.insert("men");
    // Dictionary.insert("dog");
    // Dictionary.insert("tree");
    Dictionary.insert("javascripts");
    Dictionary.insert("hpp");

    cout << Dictionary.advanceSearch(".p.") << endl;
    // cout << Dictionary.advanceSearch("javascript") << endl;
    // cout << Dictionary.startsWith("git") << endl;
    return 0;
}