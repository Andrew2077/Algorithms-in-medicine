#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> vector){

	for(int i=0;i<vector.size();++i)
		cout<<vector[i]<<" ";
	cout<<"\n\n";
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


/*int main() {
    
    int n ;
	cout<<"Enter the size of your vector: "<<endl;
    cin>>  n ;
    // this is for easy debugging 
//    vector<int> vector = { 12 ,10 , 5 ,6, 88, 15 , 0}; 

	vector<int> vector(n,50);
        for (int i=0;i <vector.size() ;++i)
                {
                    vector[i]= rand() % 50; 
                }
        
	cout<<" Before Sorting: "<<endl;
	PrintVector(vector);
	Quicksort(vector,0,vector.size()-1);
	cout<<" After Sorting: "<<endl;
	PrintVector(vector);
		
}
*/
