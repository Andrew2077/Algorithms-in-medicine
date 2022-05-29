#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;


void insertionSort(vector<int> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {        
        auto const insertion_point = 
                upper_bound(vec.begin(), it, *it);
          
        rotate(insertion_point, it, it+1);        
    }
}

int Partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void Quicksort(vector<int> &v, int start, int end ){

	if(start<end){
		int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
	
}


void introsort (vector<int> &a, int start, int end, int max_depth){
    int size = end - start;
    if (size < 16)
    {
        insertionSort(a);
        return;
    }
    if (max_depth == 0)

    {
        //http://www.cplusplus.com/reference/algorithm/sort_heap/
        sort(a.begin(), a.end());
        return;
    }
    else 
        Quicksort(a,start,end);

}


void introsort_indepthed(vector<int> &v, int start, int end)
{
    int depthLimit = 2 * log(end-start);
  
    introsort(v, start, end, depthLimit);
  
      return;
}
void PrintVector(vector<int> v){
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<" ";
	cout<<"\n\n";
}

/*int main() {
	
	vector<int> v = { 1 , 10 , 11 , 9 , 14 , 3 , 2 , 20 , 19 };
	
	cout<<"Vector Before Sorting: "<<endl;
	PrintVector(v);
	
	introsort_indepthed(v,0,v.size()-1);
	
	cout<<"Vector After Sorting: "<<endl;
	PrintVector(v);
		
}
*/
