#include <bits/stdc++.h>
using namespace std;


void multiply(int Mat1_rows, int Mat2_rows, int mat1[][2], int mat1_colums, int mat2_colums,
              int mat2[][2])
{
    int x , i, j;
    int res[Mat1_rows][mat2_colums];
    for (i = 0; i < Mat1_rows; i++) 
    {
        for (j = 0; j < mat2_colums; j++) 
        {
            res[i][j] = 0;
            for (x = 0; x < Mat2_rows; x++) 
            {
                *(*(res + i) + j) += *(*(mat1 + i) + x)
                                     * *(*(mat2 + x) + j);
            }
        }
    }
    for (i = 0; i < Mat1_rows; i++) 
    {
        for (j = 0; j < mat2_colums; j++) 
        {
            cout << *(*(res + i) + j) << " ";
        }
        cout << "\n";
    }
}

// Driver code
/*int main()
{
    int mat1[][2] = { { 2, 4 }, { 3, 4 } };
    int mat2[][2] = { { 1, 2 }, { 1, 3 } };
    int Mat1_rows = 2, Mat2_rows = 2, mat1_colums = 2, mat2_colums = 2;
  
    // Function call
    multiply(Mat1_rows, Mat2_rows, mat1, mat1_colums, mat2_colums, mat2);
    return 0;
}
*/