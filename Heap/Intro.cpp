#include <bits/stdc++.h>
using namespace std;
// ----Heap-----
// Parent(i) = i / 2;
// left Child (i) = i * 2
// Right Child (i) = ( i * 2 )+ 1

class Heap
{
public:
    vector<int> data = {NULL,50, 30, 40, 10, 5, 20, 10, 60};
    int i = 8;
    void insert(int n)
    {
        i++;
        data.push_back(n);
        int t = i;

        while (t>1)
        {
            if(data[t/2]< n){
                swap(data[t],data[t/2]);
                t/=2;
            }
            else return;
        }
    }
    //print all element
    void print(){for (int j = 1; j<= i; j++)cout<<data[j] << " ";}
    
};

int main()
{
    Heap k;
    k.insert(45);
    // k.insert(5);
    // k.insert(2);
    k.print();
    return 0;
}