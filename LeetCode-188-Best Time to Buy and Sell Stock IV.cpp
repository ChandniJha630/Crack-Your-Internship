#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        int n = prices.size();
        
        // dp array to store the maximum profit
        // dp[i][j][p]: Maximum profit on day i, with state j (0 or 1, representing not picked or picked),
        // and with p transactions remaining.
        std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(2, std::vector<int>(k + 1, 0)));
        
        // Dynamic programming iteration
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) { // 0->buy, 1->sell
                for (int p = 1; p <= k; p++) {
                    int notpick, pick;
                    if (j) {
                        // If we are in a 'sell' state (j = 1),
                        // Calculate the maximum profit for the current state
                        notpick = 0 + dp[i + 1][1][p];
                        pick = prices[i] + dp[i + 1][0][p - 1];
                    } else {
                        // If we are in a 'buy' state (j = 0),
                        // Calculate the maximum profit for the current state
                        notpick = 0 + dp[i + 1][0][p];
                        pick = -prices[i] + dp[i + 1][1][p];
                    }
                    // Update the dp array with the maximum profit
                    dp[i][j][p] = std::max(pick, notpick);
                }
            }
        }
        
        // The final result is stored in dp[0][0][k]
        return dp[0][0][k];
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    int result = solution.maxProfit(k, prices);

    std::cout << "Maximum Profit: " << result << std::endl;

    return 0;
}
