/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.If you burst the ith balloon, 
you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100

*/

#include <vector>
#include <climits>

class Solution {
    
    int solve(vector<int>& arr, int start_index, int end_index, vector<vector<int>>& dp){
        if(start_index > end_index) return 0;
        if(dp[start_index][end_index] != -1) return dp[start_index][end_index];

        int ans = 0;
        for(int k = start_index; k <= end_index; k++){
            int left_value = (start_index <= k - 1) ? solve(arr, start_index, k-1, dp) : 0;
            int right_value = (k + 1 <= end_index) ? solve(arr, k+1, end_index, dp) : 0;
            
            int temp_ans = left_value + right_value + arr[start_index-1] * arr[k] * arr[end_index+1];
            ans = max(ans, temp_ans);
        }
        dp[start_index][end_index] = ans;
        return ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> arr(n, 1);
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 1; i < n-1; i++){
            arr[i] = nums[i-1];
        }

        return solve(arr, 1, n-2, dp);
    }
};
int main() {
    Solution sol;
    std::vector<int> nums = {3, 1, 5, 8};
    
    // Call the maxCoins function and print the result
    int result = sol.maxCoins(nums);
    std::cout << "Maximum coins: " << result << std::endl;

    return 0;
}
