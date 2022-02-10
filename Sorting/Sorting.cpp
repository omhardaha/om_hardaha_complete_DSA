#include <bits/stdc++.h>
using namespace std;

void cycleSort(vector<int> &arr)//1 to N element
{
    for (int i = 0; i < arr.size(); i++)
        while (arr[i] != i + 1)
            swap(arr[i], arr[arr[i] - 1]);
};
//another method
void cycleSort2(vector<int> &arr)//1 to N element
{
    int i=0;
   while (i<arr.size())
   {
      int correctIndex = arr[i]-1;

      if(arr[i] != arr[correctIndex]) 
            swap(arr[i],arr[correctIndex]);

      else i++;   
   }
   
};

int missingNumber(vector<int> &arr)//1 to N element
{
    for (int i = 0; i < arr.size(); i++)
        while (arr[i] != i && arr[i]<arr.size()-1)
            swap(arr[i], arr[arr[i] ]);
    //  int i = 0
    for (int i=0; i < arr.size(); i++)
       if(arr[i]!=i)return i;
   
   return arr.size();
};

int main()
{
    // vector<int> arr{2,2,3,1};
    // vector<int> v{3, 5, 2, 2, 4};
    // vector<int> arr{3, 0,1};

        //  v.resize(distance(v.begin(), ip));
// if(ip==v.end())cout<<" f";
//    cout<<*ip<<endl;
//    cout<<*(v.end());
//    cout<<*ip;

    // for (auto i : arr)
    //  cout << i << " ";

    // cycleSort2(arr);
    // cout<<missingNumber(arr);
    // for (auto i : arr)
    //     cout << i << " ";

//        vector<int> vv{-1,1,-6,4,5,-6,1,4,1};
//    map<int,int> mymap;

// for(auto i:vv) mymap[i]++;
// for(auto & i:mymap)cout<<i.first<<endl;

//    mymap.insert(pair<int,int>(5,23) );
// mymap[-1]=3;
// mymap[-1]++;
// mymap[-1]++;

//    cout<<mymap[-1];
//    cout<<it;
//    mymap.insert(pair<int,int>(2,52) );
//    mymap.insert(1,1);
//    for(auto & i:mymap)cout<<i.first<<" "<<i.second<<endl;
// map<int,int>::iterator it = mymap.begin();

// for ( it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';


set<int>k{3,564,2,5};
auto it = (k.end() -3);
it--;
cout<<*it;
    return 0;
}