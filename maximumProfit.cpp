#include <bits/stdc++.h>
using namespace std;

// Time complexity O(n)
// Space complexity O(1)

int maxProfit(int arr[], int n){
	int diff = INT_MIN;
    if (n == 0) {
        return diff;
    }

    int max_so_far = arr[n-1];
    // traverse the array from the right to left
    for (int i = n - 2; i >= 0; i--)
    {
        // update `max_so_far` 
        if (arr[i] >= max_so_far) {
            max_so_far = arr[i];

        }
        // if the current element is less than the max_so_far, then update diffrent
        else {
            diff = max (diff, max_so_far - arr[i]);
        }
    }
 
    return diff;

}

int main () {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	int arr[] = { 7,6,4,3,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int result = maxProfit(arr, n);
    if (result != INT_MIN) {
        cout<<result;
    }else{
    	cout<<"0";
    }

	return 0;
}