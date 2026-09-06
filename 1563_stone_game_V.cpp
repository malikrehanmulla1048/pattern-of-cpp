#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
private:
    vector<int> prefix;
    vector<vector<int>> memo;

    // Helper to get sum of subarray [i, j] in O(1)
    int getSum(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }

    int solve(int i, int j, const vector<int>& stoneValue) {
        // Base case: only one stone left, no more points can be earned
        if (i == j) {
            return 0;
        }
        
        // Return already calculated state
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int max_score = 0;

        // Try every possible split point k between i and j-1
        for (int k = i; k < j; ++k) {
            int left_sum = getSum(i, k);
            int right_sum = getSum(k + 1, j);

            if (left_sum < right_sum) {
                // Bob throws away the larger right row
                max_score = max(max_score, left_sum + solve(i, k, stoneValue));
            } 
            else if (left_sum > right_sum) {
                // Bob throws away the larger left row
                max_score = max(max_score, right_sum + solve(k + 1, j, stoneValue));
            } 
            else {
                // Sums are equal; Alice picks the path maximizing her score
                int choose_left = left_sum + solve(i, k, stoneValue);
                int choose_right = right_sum + solve(k + 1, j, stoneValue);
                max_score = max({max_score, choose_left, choose_right});
            }
        }

        return memo[i][j] = max_score;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Initialize prefix sums
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // Initialize memoization table with -1
        memo.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, stoneValue);
    }
};
