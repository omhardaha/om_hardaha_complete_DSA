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
        vector<vector<string>> final(word.size());
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
            final[i] = (ans);
            currentWord.pop_back();
            lastNode = links[i];
        }
        return final;
    }
};
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        Trie p;
        for (auto i : products)
            p.addWord(i);
        vector<vector<string>> a = p.searchWord1(searchWord);
        return a;
    }
};
int main()
{

    return 0;
}