class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        const int NEG_INF = -1e9;

        // dp[i][j][k] = maximum amount from cell (i,j)
        // with k neutralizations remaining
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, NEG_INF))
        );

        // Base case: destination cell
        for (int k = 0; k <= 2; k++) {
            if (coins[n - 1][m - 1] < 0 && k > 0)
                dp[n - 1][m - 1][k] = 0;
            else
                dp[n - 1][m - 1][k] = coins[n - 1][m - 1];
        }

        // Fill from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                // Destination already handled
                if (i == n - 1 && j == m - 1) continue;

                for (int k = 0; k <= 2; k++) {

                    // Option 1: take current cell value
                    int bestNext = NEG_INF;

                    if (i + 1 < n)
                        bestNext = max(bestNext, dp[i + 1][j][k]);

                    if (j + 1 < m)
                        bestNext = max(bestNext, dp[i][j + 1][k]);

                    int ans = coins[i][j] + bestNext;

                    // Option 2: neutralize current negative cell
                    if (coins[i][j] < 0 && k > 0) {
                        int bestNeutral = NEG_INF;

                        if (i + 1 < n)
                            bestNeutral = max(bestNeutral, dp[i + 1][j][k - 1]);

                        if (j + 1 < m)
                            bestNeutral = max(bestNeutral, dp[i][j + 1][k - 1]);

                        ans = max(ans, bestNeutral);
                    }

                    dp[i][j][k] = ans;
                }
            }
        }

        return dp[0][0][2];
    }
};