#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int naive_counting_inversions(vector<int> a)
{

    multiset<int> set1;
    set1.insert(a[0]);
  
    int invcount = 0; 
  
    multiset<int>::iterator itset1; 
    
    int n = a.size();
    for (int i=1; i< n ; i++)
    {
        set1.insert(a[i]);
        itset1 = set1.upper_bound(a[i]);
        invcount += distance(itset1, set1.end());
    }
  
    return invcount;
}
