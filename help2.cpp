#include <bits/stdc++.h>
using namespace std;

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
    void setEnd()
    {
        flag = true;
    }
    void put(char key)
    {
        links[key - 'a'] = new Node();
    }
    Node *getNode(char key)
    {
        return links[key - 'a'];
    }
};

class Trie
{
public:
    struct Node *root;
    Trie()
    {
        root = new Node();
    }
    void addWord(string word)
    {

        Node *temp = root;
        for (auto i : word)
        {
            if (!temp->containsKey(i))
            {
                temp->put(i);
            }
            temp = temp->getNode(i);
        }
        temp->setEnd();
    }
    vector<vector<string>> searchWord1(string word)
    {
        vector<vector<string>> final;
        vector<Node *> links;
        Node *temp = root;
        string currentWord = "";
        for (auto i : word)
        {
            if (temp->containsKey(i))
            {
                currentWord += i;
                temp = temp->getNode(i);
                links.push_back(temp);
            }
            else
            {
                break;
            }
        }

        priority_queue<string> k;
        Node *lastNode = nullptr;
        for (int i = links.size() - 1; i >= 0; i--)
        {
            cout << word[i] << endl;
            queue<pair<string, Node *>> Q;
            Q.push({currentWord, links[i]});
            bool f = true;

            while (!Q.empty())
            {
                int size = Q.size();
                for (int l = 0; l < size; l++)
                {
                    auto g = Q.front();
                    Q.pop();
                    if (g.second->hasEnd())
                    {
                        k.push(g.first);
                        if (k.size() > 3)
                        {
                            k.pop();
                        }
                    };
                    for (auto c = 'a'; c <= 'z'; c++)
                    {
                        // if ((i < (links.size() - 1)) && (word[i + 1] != c) && f)
                        // {
                        //     f = false;
                        //     continue;
                        // }
                        if (g.second->containsKey(c))
                        {
                            Node *j = g.second->getNode(c);
                            if (j != lastNode)
                            {
                                Q.push({g.first + c, j});
                            }
                        };
                    }
                }
            }

            vector<string> ans;
            priority_queue<string> p = k;
            while (p.size() > 0)
            {
                ans.push_back(p.top());
                p.pop();
            };
            reverse(ans.begin(), ans.end());
            final.push_back(ans);
            currentWord.pop_back();
            lastNode = links[i];
        }
        return final;
    }
};
int main()
{
    // Trie p;
    // p.addWord("mobile");
    // p.addWord("mouse");
    // p.addWord("moneypot");
    // p.addWord("monitor");
    // p.addWord("mousepad");
    // vector<vector<string>> w = p.searchWord1("mouse");
    // for (auto i : w)
    // {
    //     cout << endl;
    //     for (auto e : i)
    //     {
    //         cout << e << " ";
    //     }
    // }
    int a = 0;
    int b = 1;
    int a1 = !a;
    int b1 = !b;
    cout<<b1;
       return 0;
}