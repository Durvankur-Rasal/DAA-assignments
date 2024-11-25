#include <iostream>
#include <vector>
#include <cstring> // For memset
using namespace std;

// Function to solve the 0/1 knapsack problem using memoization
int knapsackMemoization(int index, int remainingWeight, vector<int> &weights, vector<int> &profits, vector<vector<int>> &dp) {
    // Base case: no items left or no remaining capacity
    if (index == 0 || remainingWeight == 0) {
        return 0;
    }

    // If the result is already calculated, return it
    if (dp[index][remainingWeight] != -1) {
        return dp[index][remainingWeight];
    }

    // Exclude the current item
    int exclude = knapsackMemoization(index - 1, remainingWeight, weights, profits, dp);

    // Include the current item (if it fits in the knapsack)
    int include = 0;
    if (weights[index - 1] <= remainingWeight) {
        include = profits[index - 1] + knapsackMemoization(index - 1, remainingWeight - weights[index - 1], weights, profits, dp);
    }

    // Store the maximum of include and exclude in the memo table
    dp[index][remainingWeight] = max(include, exclude);

    return dp[index][remainingWeight];
}

int main() {
    int n, W;

    // Input the number of items and maximum weight
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    vector<int> weights(n), profits(n);

    // Input the weights and profits of the items
    for (int i = 0; i < n; i++) {
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> weights[i];
        cout << "Enter profit of item " << i + 1 << ": ";
        cin >> profits[i];
    }

    // Create a memoization table and initialize with -1
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    // Solve the problem using memoization
    int maxProfit = knapsackMemoization(n, W, weights, profits, dp);

    // Output the maximum profit
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
