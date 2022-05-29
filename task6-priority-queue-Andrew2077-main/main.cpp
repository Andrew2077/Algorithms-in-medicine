#include "my_pq.h"
#include <iostream>
using namespace std;


int main(){
    
    int tmp;
    int Heap_Size;
    cin>> Heap_Size ;

    int Number_of_Operations;
    cin>>Number_of_Operations;
    
    vector<int> arr ;
        for (int i = 0; i < Heap_Size; i++)
        {
            cin>>tmp;
            arr.push_back(tmp);
        }

    My_PQ pq_tree(arr);

    int Operation_methode;
    int index;
    int priority;

    for (int i = 1; i <= Number_of_Operations; i++)
    {
        cin>>Operation_methode;
        switch (Operation_methode)
        {
        case 1:
            cin>>tmp;
            pq_tree.insert(tmp);
            break;
        
        case 2:
            cin >> index;
            cin >> priority;
            pq_tree.change_priority(index, priority);
            break;

        case 3:
            cin>> index;
            pq_tree.remove(index);
            break;

        case 4:
            pq_tree.Extract_Max();
            break;

        case 5:
            cout<< pq_tree.peek()<<" "<<endl;
            break;

        case 6:
            pq_tree.Print_Elements();
            cout << " " << endl; 
            break;

        case 7 :
            cout << pq_tree.Size() << " " << endl;
            break;
        }
    }
    
}

