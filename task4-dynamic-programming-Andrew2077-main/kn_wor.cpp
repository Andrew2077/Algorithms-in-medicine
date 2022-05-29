//0-1 kanpsack 
#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns
// maximum of two integers
int max(int Element_1, int Element_2)
{
    return (Element_1 > Element_2) ? Element_1 : Element_2;
}
 

//bottom_up table for knapsack


int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    // recursion table

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)

            	K[i][w] = max (K[i-1][w] , K[i-1][w-wt[i-1]] + val[i-1]);

            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
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
    cout << knapSack(W, wt, val, n);
    return 0;
}
