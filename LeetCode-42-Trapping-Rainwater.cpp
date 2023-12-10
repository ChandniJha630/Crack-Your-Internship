/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 
Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& h) {
        int l = 0, r = h.size() - 1;   // Two pointers, one starting from the left and the other from the right
        int lmax = 0, rmax = 0;         // Variables to keep track of the maximum height encountered from the left and right
        int ans = 0;                    // Variable to store the total trapped water

        // Loop until the two pointers meet
        while (r >= l) {
            lmax = std::max(h[l], lmax); // Update the maximum height encountered from the left
            rmax = std::max(h[r], rmax); // Update the maximum height encountered from the right

            // Add the trapped water at the current position
            // The trapped water is the minimum of the maximum heights from the left and right, minus the height at the current position
            ans += (lmax < rmax) ? lmax - h[l++] : rmax - h[r--];
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trappedWater = solution.trap(heights);

    std::cout << "Trapped Water: " << trappedWater << std::endl;

    return 0;
}
