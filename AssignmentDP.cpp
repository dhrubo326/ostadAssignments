// Time Complexity : O(N2)
// Space Complexity : O(N2)
#include <bits/stdc++.h>
using namespace std;

class Solve {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums), vector<int>(1+size(nums), -1));   
        return solve(nums, 0, -1);
    }
    int solve(vector<int>& nums, int i, int prev_i) {
        if(i >= size(nums)) return 0;
        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
        int take = 0, dontTake = solve(nums, i + 1, prev_i);
        if(prev_i == -1 || nums[i] > nums[prev_i]) take = 1 + solve(nums, i + 1, i);
        return dp[i][prev_i+1] = max(take, dontTake);
    }
};


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    return 0;
}