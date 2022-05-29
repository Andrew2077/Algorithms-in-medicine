#include <bits/stdc++.h>
#include <vector>
using namespace std;



    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }

int main()
{
    // "7\r\n2 3 0 1 2 2 4"
    int temp ;
    int n;
    cin>> n ;

	vector<int> nums ;
     for (int i = 0; i < n ; i++ ){
        cin>> temp ;
        nums.push_back(temp);
        }

	cout << lengthOfLIS(nums) ;

	return 0;
}
