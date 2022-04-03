#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?
class Trie
{
public:
    struct Node
    {
        Node *links[26];
        bool flag = false;
        int count = 0;
        int prefCount = 0;
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
            p->prefCount++;
        }
        p->count++;
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
        return p->count > 0;
    }
    int countWordsEqualTo(string word)
    {
        Node *p = root;
        for (char key : word)
        {
            if (!p->containsKey(key))
            {
                return 0;
            }
            p = p->getNode(key);
        }
        return p->count;
    }
    int countWordsStartingWith(string word)
    {
        Node *p = root;
        for (char key : word)
        {
            if (!p->containsKey(key))
            {
                return 0;
            }
            p = p->getNode(key);
        }
        return p->prefCount;
    }
    void erase(string word)
    {
        if (search(word))
        {
            Node *p = root;
            for (char key : word)
            {
                // if (!p->containsKey(key))
                // {
                //     p->put(key);
                // }
                p = p->getNode(key);
                p->prefCount--;
            }
            p->count--;
        }
    }
};

int main()
{

    Trie Dictionary;
    // Dictionary.insert("men");
    // Dictionary.insert("dog");
    // Dictionary.insert("tree");
    Dictionary.insert("samsung");
    Dictionary.insert("samsung");
    Dictionary.insert("sams");
    Dictionary.insert("vivo");

    cout << Dictionary.countWordsEqualTo("samsung") << endl;   // 2
    cout << Dictionary.countWordsStartingWith("sams") << endl; // 3

    Dictionary.erase("samsung");

    cout << Dictionary.countWordsStartingWith("sams") << endl; // 3
    // cout << Dictionary.advanceSearch("javascript") << endl;
    // cout << Dictionary.startsWith("git") << endl;
    return 0;
}