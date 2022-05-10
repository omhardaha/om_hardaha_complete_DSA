#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"enter no. of pages - ";
    cin>>n;

    vector<int> pages (n);

    cout<<"enter pages  "<<endl;
    for(auto &i : pages) cin>> i;

    int frameSize ;
    cout<<"enter frame Size - ";
    cin>>frameSize;

    set<int> block;
    queue<int> Q;

    int fault = 0;

    for (auto i : pages)
    {
        if (block.find(i) == block.end())
        {
            fault++;
            if (Q.size() < frameSize)
            {
                Q.push(i);
                block.insert(i);
            }
            else
            {
                block.erase(Q.front());
                Q.pop();
                Q.push(i);
                block.insert(i);
            }
        }
    }
    cout <<"page fault is - "<< fault;
    return 0;
}