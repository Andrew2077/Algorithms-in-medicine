#ifndef MY_PQ_H
#define MY_PQ_H
//code from Binary heap-Geeks for geeks
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class My_PQ{
private:

    int size = -1;
    int printo;
    
    vector<int> Elements;
   // vector<int>::iterator it;
    
    int Parent(int i)   
    {
	    return (i - 1) / 2;
    }
    
    int Left_Child(int i)
    {
	    return ((2 * i) + 1);
    }
    
    int Right_Child(int i)
    {
        return ((2 * i) + 2);
    }

    void Up_shift(int i)
    {
        while (i > 0 && Elements[Parent(i)] < Elements[i]) {
            swap(Elements[Parent(i)], Elements[i]);
            i = Parent(i);
        }
    }

    void Down_shift(int i)
    {

        int maxIndex = i;
        int l = Left_Child(i);

        if (l <= size && Elements[l] > Elements[maxIndex]) {
            maxIndex = l;
        }

        int r = Right_Child(i);
        if (r <= size && Elements[r] > Elements[maxIndex]) {
            maxIndex = r;
        }

        if (i != maxIndex) {
            swap(Elements[i], Elements[maxIndex]);
            Down_shift(maxIndex);
        }
    }


public:
    My_PQ(){}
    
    ~My_PQ() {}

    My_PQ(vector<int> arr)
    {
        for(int x : arr){
            insert(x);
            sort(Elements.begin(), Elements.end(), greater<int>());
        }
    }
    
    int Extract_Max()
    {
        int result = Elements[0];
        Elements[0] = Elements[size];
        size = size - 1;
        Down_shift(0);
        sort(Elements.begin(), Elements.end(), greater<int>());
        return result;
    }

    void change_priority(int index, int new_priority)
    {
        int old_priority = Elements[index];
	    Elements[index] = new_priority;
        if (new_priority > old_priority) {
            Up_shift(index);
            sort(Elements.begin(), Elements.end(), greater<int>());
        }
        else {
            Down_shift(index);
            sort(Elements.begin(), Elements.end(), greater<int>());
        }
    }

    int peek()
    {
        return Elements[0];
    }

    void insert(int value)
    {
        size = size + 1;
        if (size  == Elements.size())
            Elements.push_back(value);
        else
            Elements[size] = value;
        Up_shift(size);
    } 

    void remove(int index)
    {
        Elements[index] = peek() + 1;
        Up_shift(index);
        Extract_Max();
       // it = Elements.begin();
       // Elements.erase(it);
       sort(Elements.begin(), Elements.end(), greater<int>());
    }

    int Size()
    {
        return size + 1;
    }

    void Print_Elements() {
        
        sort(Elements.begin(), Elements.end(), greater<int>());
        
        for (int i = 0; i <= size; i++) {
            cout << Elements[i] << " ";
        }
    
    }
};

#endif
