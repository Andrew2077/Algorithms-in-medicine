
#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, int n,
					int val[], int wt[])
{
	// dp[i] is going to be our array that holds all of our solutions +1 for the zero solution right ?! 

	int dp[W+1];

	// sets all the values insdie the array with Zeros memeset(box , object , how many)
	memset(dp, 0, sizeof dp);

	// Fill dp[] using above recursive formula

	for (int i=0; i<=W; i++)
		//weight is our prio, K[Weight][value] unlike 0/1 problem 
	for (int j=0; j<n; j++)
		if (wt[j] <= i)// this condition for minimium cases where u can't go below 0 index in arrays 

			dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);//recursion takes places J times each i run 

	return dp[W];
}

int main()
{
	int n;
//	cout<< "enter size";
	cin>> n ;
	int W ;
//	cout<< "enter Weight";
	cin >> W ;

    int wt[n];
        for ( int i = 0 ; i < n ; i++){
            int temp ;
            cin>> temp ;
            wt[i] =  temp;
        }
        
    int val[n];
        for ( int i = 0 ; i < n ; i++){
            int temp ;
            cin>> temp ;
            val[i] =  temp;
        }
 
	cout << unboundedKnapsack(W, n, val, wt);

	return 0;
}
